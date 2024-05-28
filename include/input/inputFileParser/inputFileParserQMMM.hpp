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

#ifndef _INPUT_FILE_PARSER_QMMM_HPP_

#define _INPUT_FILE_PARSER_QMMM_HPP_

#include <cstddef>   // for size_t
#include <string>    // for string
#include <vector>    // for vector

#include "inputFileParser.hpp"   // for InputFileParser

namespace engine
{
    class Engine;   // Forward declaration
}

namespace input
{
    /**
     * @class InputFileParserQMMM inherits from InputFileParser
     *
     * @brief Parses the general commands in the input file
     *
     */
    class InputFileParserQMMM : public InputFileParser
    {
       public:
        explicit InputFileParserQMMM(engine::Engine &);

        void parseQMCenter(const std::vector<std::string> &lineElements, const size_t lineNumber);
        void parseQMOnlyList(const std::vector<std::string> &lineElements, const size_t lineNumber);
        void parseMMOnlyList(const std::vector<std::string> &lineElements, const size_t lineNumber);

        void parseUseQMCharges(
            const std::vector<std::string> &lineElements,
            const size_t                    lineNumber
        );

        void parseQMCoreRadius(
            const std::vector<std::string> &lineElements,
            const size_t                    lineNumber
        );

        void parseQMMMLayerRadius(
            const std::vector<std::string> &lineElements,
            const size_t                    lineNumber
        );

        void parseQMMMSmoothingRadius(
            const std::vector<std::string> &lineElements,
            const size_t                    lineNumber
        );
    };

}   // namespace input

#endif   // _INPUT_FILE_PARSER_QMMM_HPP_