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

#ifndef _NON_COULOMB_PAIR_HPP_

#define _NON_COULOMB_PAIR_HPP_

#include <cstddef>   // for size_t
#include <utility>   // for pair

namespace potential
{
    /**
     * @class NonCoulombPair
     *
     * @brief base class representing a pair of non-coulombic types
     *
     * @details constructor with van der Waals types and cut-off radius is for
     * force field parameters constructor with cut-off radius only is for guff
     * representation
     *
     */
    class NonCoulombPair
    {
       protected:
        size_t _vanDerWaalsType1 = 0;
        size_t _vanDerWaalsType2 = 0;
        size_t _internalType1    = 0;
        size_t _internalType2    = 0;

        double _radialCutOff;
        double _energyCutOff = 0.0;
        double _forceCutOff  = 0.0;

       public:
        explicit NonCoulombPair(
            const size_t vanDerWaalsType1,
            const size_t vanDerWaalsType2,
            const double cutOff
        )
            : _vanDerWaalsType1(vanDerWaalsType1),
              _vanDerWaalsType2(vanDerWaalsType2),
              _radialCutOff(cutOff){};

        explicit NonCoulombPair(const double cutOff) : _radialCutOff(cutOff){};

        explicit NonCoulombPair(
            const double cutoff,
            const double energyCutoff,
            const double forceCutoff
        )
            : _radialCutOff(cutoff),
              _energyCutOff(energyCutoff),
              _forceCutOff(forceCutoff){};

        virtual ~NonCoulombPair() = default;

        [[nodiscard]] bool operator==(const NonCoulombPair &other) const;
        [[nodiscard]] virtual std::pair<double, double> calculateEnergyAndForce(
            const double distance
        ) const = 0;

        /********************
         * standard setters *
         ********************/

        void setInternalType1(const size_t internalType1)
        {
            _internalType1 = internalType1;
        }
        void setInternalType2(const size_t internalType2)
        {
            _internalType2 = internalType2;
        }
        void setEnergyCutOff(const double energyCutoff)
        {
            _energyCutOff = energyCutoff;
        }
        void setForceCutOff(const double forceCutoff)
        {
            _forceCutOff = forceCutoff;
        }

        /********************
         * standard getters *
         ********************/

        [[nodiscard]] size_t getVanDerWaalsType1() const
        {
            return _vanDerWaalsType1;
        }
        [[nodiscard]] size_t getVanDerWaalsType2() const
        {
            return _vanDerWaalsType2;
        }
        [[nodiscard]] size_t getInternalType1() const { return _internalType1; }
        [[nodiscard]] size_t getInternalType2() const { return _internalType2; }
        [[nodiscard]] double getRadialCutOff() const { return _radialCutOff; }
        [[nodiscard]] double getEnergyCutOff() const { return _energyCutOff; }
        [[nodiscard]] double getForceCutOff() const { return _forceCutOff; }
    };

}   // namespace potential

#endif   // _NON_COULOMB_PAIR_HPP_