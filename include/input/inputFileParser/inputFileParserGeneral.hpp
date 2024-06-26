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

#ifndef _INPUT_FILE_PARSER_GENERAL_HPP_

#define _INPUT_FILE_PARSER_GENERAL_HPP_

#include "inputFileParser.hpp"   // for InputFileParser

#include <cstddef>   // for size_t
#include <memory>    // for unique_ptr
#include <string>    // for string
#include <vector>    // for vector

namespace engine
{
    class Engine;   // Forward declaration
}

namespace input
{
    /**
     * @class InputFileParserGeneral inherits from InputFileParser
     *
     * @brief Parses the general commands in the input file
     *
     */
    class InputFileParserGeneral : public InputFileParser
    {
      public:
        explicit InputFileParserGeneral(engine::Engine &);

        void parseJobType(const std::vector<std::string> &lineElements, const size_t lineNumber);
        void parseDimensionality(const std::vector<std::string> &lineElements, const size_t lineNumber);

        void parseJobTypeForEngine(const std::vector<std::string> &, const size_t, std::unique_ptr<engine::Engine> &);
    };

}   // namespace input

#endif   // _INPUT_FILE_PARSER_GENERAL_HPP_