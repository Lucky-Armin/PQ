/*****************************************************************************
<GPL_HEADER>

    PIMD-QMCF
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

#include "qmRunner.hpp"

#include "constants/conversionFactors.hpp"   // for _HARTREE_PER_BOHR_TO_KCAL_PER_MOL_PER_ANGSTROM_, _HARTREE_TO_KCAL_PER_MOL_
#include "exceptions.hpp"                    // for InputFileException
#include "physicalData.hpp"                  // for PhysicalData
#include "qmSettings.hpp"                    // for QMSettings
#include "simulationBox.hpp"                 // for SimulationBox
#include "vector3d.hpp"                      // for Vec3D

#include <algorithm>    // for __for_each_fn, for_each
#include <format>       // for format
#include <fstream>      // for ofstream
#include <functional>   // for identity
#include <string>       // for string

using QM::QMRunner;

/**
 * @brief run the qm engine
 *
 * @param simBox
 */
void QMRunner::run(simulationBox::SimulationBox &simBox, physicalData::PhysicalData &physicalData)
{
    writeCoordsFile(simBox);
    execute();
    readForceFile(simBox, physicalData);
    readStressTensor(simBox.getBox(), physicalData);
}

/**
 * @brief reads the force file (including qm energy) and sets the forces of the atoms
 *
 * @param box
 * @param physicalData
 */
void QMRunner::readForceFile(simulationBox::SimulationBox &box, physicalData::PhysicalData &physicalData)
{
    const std::string forceFileName = "qm_forces";

    std::ifstream forceFile(forceFileName);

    if (!forceFile.is_open())
        throw customException::QMRunnerException(
            std::format("Cannot open {} force file \"{}\"", string(settings::QMSettings::getQMMethod()), forceFileName));

    double energy = 0.0;

    forceFile >> energy;

    physicalData.setQMEnergy(energy * constants::_HARTREE_TO_KCAL_PER_MOL_);

    auto readForces = [&forceFile](auto &atom)
    {
        auto grad = linearAlgebra::Vec3D();

        forceFile >> grad[0] >> grad[1] >> grad[2];

        atom->setForce(-grad * constants::_HARTREE_PER_BOHR_TO_KCAL_PER_MOL_PER_ANGSTROM_);
    };

    std::ranges::for_each(box.getQMAtoms(), readForces);

    forceFile.close();
}