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

#include "inputFileParserForceField.hpp"

#include <cstddef>      // for size_t
#include <format>       // for format
#include <functional>   // for _Bind_front_t, bind_front

#include "engine.hpp"                 // for Engine
#include "exceptions.hpp"             // for InputFileException, customException
#include "forceFieldClass.hpp"        // for ForceField
#include "forceFieldNonCoulomb.hpp"   // for ForceFieldNonCoulomb
#include "forceFieldSettings.hpp"     // for ForceFieldSettings
#include "potential.hpp"              // for Potential
#include "stringUtilities.hpp"        // for toLowerCopy

using namespace input;

/**
 * @brief Construct a new Input File Parser Force Field:: Input File Parser
 * Force Field object
 *
 * @details following keywords are added to the _keywordFuncMap,
 * _keywordRequiredMap and _keywordCountMap: 1) force-field <on/off/bonded>
 *
 * @param engine
 */
InputFileParserForceField::InputFileParserForceField(engine::Engine &engine)
    : InputFileParser(engine)
{
    addKeyword(
        std::string("force-field"),
        bind_front(&InputFileParserForceField::parseForceFieldType, this),
        false
    );
}

/**
 * @brief Parse the integrator used in the simulation
 *
 * @details Possible options are:
 * 1) "on"  - force-field is activated
 * 2) "off" - force-field is deactivated (default)
 * 3) "bonded" - only bonded interactions are activated
 *
 * @param lineElements
 *
 * @throws InputFileException if force-field is not valid - currently only on,
 * off and bonded are supported
 */
void InputFileParserForceField::parseForceFieldType(
    const std::vector<std::string> &lineElements,
    const size_t                    lineNumber
)
{
    checkCommand(lineElements, lineNumber);

    const auto forceFieldType = utilities::toLowerCopy(lineElements[2]);

    if (forceFieldType == "on")
    {
        settings::ForceFieldSettings::activate();
        _engine.getForceFieldPtr()->activateNonCoulombic();
        _engine.getPotential().makeNonCoulombPotential(
            potential::ForceFieldNonCoulomb()
        );
    }
    else if (forceFieldType == "off")
    {
        settings::ForceFieldSettings::deactivate();
        _engine.getForceFieldPtr()->deactivateNonCoulombic();
    }
    else if (forceFieldType == "bonded")
    {
        settings::ForceFieldSettings::activate();
        _engine.getForceFieldPtr()->deactivateNonCoulombic();
    }
    else
        throw customException::InputFileException(format(
            "Invalid force-field keyword \"{}\" at line {} "
            "in input file\n"
            "Possible keywords are \"on\", \"off\" or \"bonded\"",
            lineElements[2],
            lineNumber
        ));
}