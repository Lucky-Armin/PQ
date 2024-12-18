/*****************************************************************************
<GPL_HEADER>

    PQ
    Copyright (C) 2023-now  Jakob Gamper

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

<GPL_HEADER>
******************************************************************************/

#include "hybridSetup.hpp"

#include <algorithm>     // for min, unique
#include <cstddef>       // for size_t
#include <format>        // for format
#include <ranges>        // for sort
#include <string>        // for string
#include <string_view>   // for string_view
#include <vector>        // for vector

#include "engine.hpp"           // for QMMMMDEngine
#include "exceptions.hpp"       // for InputFileException
#include "fileSettings.hpp"     // for FileSettings
#include "hybridSettings.hpp"   // for HybridSettings
#include "settings.hpp"         // for Settings

#ifdef PYTHON_ENABLED
#include "selection.hpp"   // for select
#endif

using setup::HybridSetup;
using namespace settings;
using namespace engine;
using namespace customException;

/**
 * @brief wrapper to build HybridSetup object and call setup
 *
 * @param engine
 */
void setup::setupHybrid(Engine &engine)
{
    if (!Settings::isQMMMActivated())
        return;

    engine.getStdoutOutput().writeSetup("QMMM setup");
    engine.getLogOutput().writeSetup("QMMM setup");

    HybridSetup qmmmSetup(engine);
    qmmmSetup.setup();
}

/**
 * @brief Construct a new HybridSetup object
 *
 * @param engine
 */
HybridSetup::HybridSetup(Engine &engine) : _engine(engine){};

/**
 * @brief setup QMMM-MD
 *
 */
void HybridSetup::setup()
{
    setupQMCenter();
    setupQMOnlyList();
    setupMMOnlyList();
    throw UserInputException("Not implemented yet");
}

/**
 * @brief setup QM center
 *
 * @details This function determines the indices of the atoms that should be
 * treated as the QM center. The QM center is the region of the system that is
 * treated with QM methods. All atomIndices that are part of the QM center are
 * added to the QM center list in the simulation box.
 *
 */
void HybridSetup::setupQMCenter()
{
    const auto qmCenterString = HybridSettings::getCoreCenterString();
    const auto qmCenter       = parseSelection(qmCenterString, "qm_center");

    _engine.getSimulationBox().addQMCenterAtoms(qmCenter);
}

/**
 * @brief setup QM only list
 *
 */
void HybridSetup::setupQMOnlyList()
{
    const auto qmOnlyListString = HybridSettings::getCoreOnlyListString();
    const auto qmOnlyList = parseSelection(qmOnlyListString, "qm_only_list");

    _engine.getSimulationBox().setupQMOnlyAtoms(qmOnlyList);
}

/**
 * @brief setup MM only list
 *
 */
void HybridSetup::setupMMOnlyList()
{
    const auto mmOnlyListString = HybridSettings::getNonCoreOnlyListString();
    const auto mmOnlyList = parseSelection(mmOnlyListString, "mm_only_list");

    _engine.getSimulationBox().setupMMOnlyAtoms(mmOnlyList);
}

/**
 * @brief parse selection string
 *
 * @details This function parses a string that contains a selection of atoms.
 * The selection can be a list of atom indices or a selection string that is
 * understood by the PQAnalysis Python package. In order to use the full
 * selection parser power of the PQAnalysis Python package, the PQ build must be
 * compiled with Python bindings. If the PQ build is compiled without Python
 * bindings, the selection string must be a comma-separated list of integers or
 * a - separated range of indices, representing the atom indices in the restart
 * file that should be treated as the selection. If the selection is empty, the
 * function returns a vector with a single element, 0.
 *
 * @param selection The selection string
 * @param key The key of the selection string
 *
 * @return std::vector<int> The selection vector
 *
 * @throws customException::InputFileException if the selection string contains
 * characters that are not digits, "-" or commas and the PQ build is compiled
 * without Python bindings.
 */
std::vector<int> HybridSetup::parseSelection(
    const std::string &selection,
    const std::string &key
)
{
    std::string restartFile = FileSettings::getStartFileName();
    std::string moldescFile = FileSettings::getMolDescriptorFileName();

    std::vector<int> selectionVec;

    if (selection.empty())
        return {0};

    auto needsPython = false;
    if (selection.find_first_not_of("0123456789,-") != std::string::npos)
        needsPython = true;

#ifdef PYTHON_ENABLED
    if (needsPython)
        selectionVec = pq_python::select(selection, restartFile, moldescFile);
#else

    // check if string contains any characters that are not digits or commas
    if (needsPython)
    {
        throw InputFileException(std::format(
            "The value of key {} - {} contains characters that are not digits, "
            "\"-\" or commas. The current build of PQ was compiled without "
            "Python bindings, so the {} string must be a comma-separated list "
            "of integers, representing the atom indices in the restart file "
            "that should be treated as the {}. In order to use the full "
            "selection parser power of the PQAnalysis Python package, the PQ "
            "build must be compiled with Python bindings.",
            key,
            selection,
            key,
            key
        ));
    }
#endif

    if (!needsPython)
        selectionVec = parseSelectionNoPython(selection, key);

    std::ranges::sort(selectionVec);
    auto ret = std::ranges::unique(selectionVec);
    selectionVec.erase(ret.begin(), ret.end());

    return selectionVec;
}

/**
 * @brief parse selection string without Python
 *
 * @param selection The selection string
 * @param key The key of the selection string
 *
 * @return std::vector<int> The selection vector
 *
 * @throws customException::InputFileException if the selection string is an
 * empty list
 */
std::vector<int> HybridSetup::parseSelectionNoPython(
    const std::string &selection,
    const std::string &key
)
{
    // parse the qm_center string
    std::vector<int> selectionVec;

    size_t pos = 0;
    while (pos < selection.size())
    {
        size_t nextPos = selection.find(',', pos);
        if (nextPos == std::string::npos)
            nextPos = selection.size();

        std::string_view atomIndexStr(selection.c_str() + pos, nextPos - pos);

        // remove all whitespaces from the atom index string
        atomIndexStr.remove_prefix(
            std::min(atomIndexStr.find_first_not_of(" "), atomIndexStr.size())
        );
        const auto min = std::min(
            atomIndexStr.find_last_not_of(" ") + 1,
            atomIndexStr.size()
        );
        atomIndexStr.remove_suffix(atomIndexStr.size() - min);

        // check if the atom index string is a range of indices
        size_t rangePos = atomIndexStr.find('-');
        if (rangePos != std::string::npos)
        {
            const auto startString = atomIndexStr.substr(0, rangePos);
            const auto endString   = atomIndexStr.substr(rangePos + 1);
            int        start       = std::stoi(std::string(startString));
            int        end         = std::stoi(std::string(endString));

            for (int i = start; i <= end; ++i) selectionVec.push_back(i);

            pos = nextPos + 1;
            continue;
        }

        selectionVec.push_back(std::stoi(std::string(atomIndexStr)));
        pos = nextPos + 1;
    }

    // check if the selection vector is empty or contains duplicates
    if (selectionVec.empty())
    {
        throw customException::InputFileException(std::format(
            "The value of key {} - {} is an empty list. The {} string must be "
            "a comma-separated list of integers or ranges, representing the "
            "atom indices in the restart file that should be treated as the "
            "{}.",
            key,
            selection,
            key,
            key
        ));
    }

    return selectionVec;
}