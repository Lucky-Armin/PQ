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

#include "engine.hpp"                      // for Engine
#include "exceptions.hpp"                  // for InputFileException, customException
#include "forceFieldClass.hpp"             // for ForceField
#include "forceFieldSettings.hpp"          // for ForceFieldSettings
#include "inputFileParser.hpp"             // for readInput
#include "inputFileParserForceField.hpp"   // for InputFileParserForceField
#include "testInputFileReader.hpp"         // for TestInputFileReader
#include "throwWithMessage.hpp"            // for ASSERT_THROW_MSG

#include "gtest/gtest.h"   // for AssertionResult, Message
#include <gtest/gtest.h>   // for EXPECT_FALSE, EXPECT_TRUE
#include <string>          // for string, allocator, basic_string
#include <vector>          // for vector

using namespace input;

/**
 * @brief tests parsing the "force-field" command
 *
 * @details possible options are on, off or bonded - otherwise throws inputFileException
 *
 */
TEST_F(TestInputFileReader, testParseForceField)
{
    InputFileParserForceField parser(*_engine);
    std::vector<std::string>  lineElements = {"force-field", "=", "on"};
    parser.parseForceFieldType(lineElements, 0);
    EXPECT_TRUE(settings::ForceFieldSettings::isActive());
    EXPECT_TRUE(_engine->getForceFieldPtr()->isNonCoulombicActivated());

    lineElements = {"force-field", "=", "off"};
    parser.parseForceFieldType(lineElements, 0);
    EXPECT_FALSE(settings::ForceFieldSettings::isActive());
    EXPECT_FALSE(_engine->getForceFieldPtr()->isNonCoulombicActivated());

    lineElements = {"force-field", "=", "bonded"};
    parser.parseForceFieldType(lineElements, 0);
    EXPECT_TRUE(settings::ForceFieldSettings::isActive());
    EXPECT_FALSE(_engine->getForceFieldPtr()->isNonCoulombicActivated());

    lineElements = {"forceField", "=", "notValid"};
    ASSERT_THROW_MSG(
        parser.parseForceFieldType(lineElements, 0),
        customException::InputFileException,
        "Invalid force-field keyword \"notValid\" at line 0 in input file - possible keywords are \"on\", \"off\" or \"bonded\"");
}