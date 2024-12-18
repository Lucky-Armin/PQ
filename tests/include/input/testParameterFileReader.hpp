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

#ifndef _TEST_PARAMETER_FILE_READER_HPP_

#define _TEST_PARAMETER_FILE_READER_HPP_

#include <gtest/gtest.h>   // for Test

#include <string>   // for allocator

#include "fileSettings.hpp"          // for FileSettings
#include "mmmdEngine.hpp"            // for Engine
#include "molecule.hpp"              // for Molecule
#include "parameterFileReader.hpp"   // for ParameterFileReader
#include "simulationBox.hpp"         // for SimulationBox

/**
 * @class TestParameterFileReader
 *
 * @brief Fixture class for testing the ParameterFileReader class
 *
 */
class TestParameterFileReader : public ::testing::Test
{
   protected:
    engine::Engine                            *_engine;
    input::parameterFile::ParameterFileReader *_parameterFileReader;

    void SetUp() override
    {
        auto molecule1 = simulationBox::Molecule();
        molecule1.setNumberOfAtoms(1);

        auto molecule2 = simulationBox::Molecule();
        molecule2.setNumberOfAtoms(2);

        // NOTE: use dummy engine for testing
        //       this is implemented by base class Engine
        //       and works therefore for all derived classes
        _engine = new engine::MMMDEngine();

        _engine->getSimulationBox().addMolecule(molecule1);
        _engine->getSimulationBox().addMolecule(molecule2);

        _parameterFileReader = new input::parameterFile::ParameterFileReader(
            "data/parameterFileReader/param.param",
            *_engine
        );
        settings::FileSettings::setIsParameterFileNameSet();
    }

    void TearDown() override
    {
        delete _parameterFileReader;
        delete _engine;
    }
};

#endif   // _TEST_PARAMETER_FILE_READER_HPP_