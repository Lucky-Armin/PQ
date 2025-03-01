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

#ifndef _RING_POLYMER_ENERGY_OUTPUT_HPP_

#define _RING_POLYMER_ENERGY_OUTPUT_HPP_

#include <cstddef>   // for size_t
#include <vector>    // for vector

#include "output.hpp"        // for Output
#include "typeAliases.hpp"   // for VecPhysicalData

namespace output
{
    /**
     * @class RingPolymerEnergyOutput inherits from Output
     *
     * @brief Output file for spring energies
     *
     */
    class RingPolymerEnergyOutput : public Output
    {
       public:
        using Output::Output;

        void write(const size_t step, const pq::VecPhysicalData &);

        double sumOfRingPolymerEnergies(const pq::VecPhysicalData &);
        double maxRingPolymerEnergy(const pq::VecPhysicalData &);
    };

}   // namespace output

#endif   // _RING_POLYMER_ENERGY_OUTPUT_HPP_