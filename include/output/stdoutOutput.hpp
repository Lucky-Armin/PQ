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

#ifndef _STDOUT_OUTPUT_HPP_

#define _STDOUT_OUTPUT_HPP_

#include "output.hpp"

namespace output
{
    /**
     * @class StdoutOutput inherits from Output
     *
     * @brief Output file for stdout
     *
     */
    class StdoutOutput : public Output
    {
       public:
        using Output::Output;

        void writeInfo(const std::string &message) const;

        void writeHeader() const;
        void writeEndedNormally(const double elapsedTime) const;

        void writeDensityWarning() const;
        void writeOptWarning(const std::string &message) const;

        void writeSetup(const std::string &setup) const;
        void writeSetupWarning(const std::string &setup) const;
        void writeSetupCompleted() const;
        void writeRead(const std::string &, const std::string &) const;
    };

}   // namespace output

#endif   // _STDOUT_OUTPUT_HPP_