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

#ifndef _MANOSTAT_INPUT_PARSER_HPP_

#define _MANOSTAT_INPUT_PARSER_HPP_

#include <cstddef>   // for size_t
#include <string>    // for string
#include <vector>    // for vector

#include "inputFileParser.hpp"   // for InputFileParser
#include "typeAliases.hpp"       // for pq::strings

namespace input
{
    /**
     * @class ManostatInputParser inherits from InputFileParser
     *
     * @brief Parses the manostat commands in the input file
     *
     */
    class ManostatInputParser : public InputFileParser
    {
       public:
        explicit ManostatInputParser(pq::Engine &);

        void parseManostat(const pq::strings &, const size_t);
        void parsePressure(const pq::strings &, const size_t);
        void parseManostatRelaxationTime(const pq::strings &, const size_t);
        void parseCompressibility(const pq::strings &, const size_t);
        void parseIsotropy(const pq::strings &, const size_t);
    };

}   // namespace input

#endif   // _MANOSTAT_INPUT_PARSER_HPP_