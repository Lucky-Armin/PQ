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

#include "timingsInputParser.hpp"

#include <functional>    // for _Bind_front_t, bind_front
#include <string_view>   // for string_view

#include "exceptions.hpp"        // for InputFileException
#include "timingsSettings.hpp"   // for TimingsSettings

using namespace input;
using namespace engine;
using namespace customException;
using namespace settings;

/**
 * @brief Construct a new Input File Parser Timings object
 *
 * @details following keywords are added to the _keywordFuncMap,
 * _keywordRequiredMap and _keywordCountMap: 1) timestep <double> (required) 2)
 * nstep <size_t> (required)
 *
 * @param engine
 */
TimingsInputParser::TimingsInputParser(Engine &engine) : InputFileParser(engine)
{
    addKeyword(
        std::string("timestep"),
        bind_front(&TimingsInputParser::parseTimeStep, this),
        false
    );

    addKeyword(
        std::string("nstep"),
        bind_front(&TimingsInputParser::parseNumberOfSteps, this),
        true
    );
}

/**
 * @brief parse timestep of simulation and set it in timings
 *
 * @param lineElements
 */
void TimingsInputParser::parseTimeStep(
    const std::vector<std::string> &lineElements,
    const size_t                    lineNumber
)
{
    checkCommand(lineElements, lineNumber);
    TimingsSettings::setTimeStep(stod(lineElements[2]));
}

/**
 * @brief parse number of steps of simulation and set it in timings
 *
 * @param lineElements
 *
 * @throws InputFileException if number of steps is negative
 */
void TimingsInputParser::parseNumberOfSteps(
    const std::vector<std::string> &lineElements,
    const size_t                    lineNumber
)
{
    checkCommand(lineElements, lineNumber);

    const auto numberOfSteps = stoi(lineElements[2]);

    if (numberOfSteps < 0)
        throw InputFileException("Number of steps cannot be negative");

    TimingsSettings::setNumberOfSteps(size_t(numberOfSteps));
}