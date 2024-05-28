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

#include <gtest/gtest.h>   // for Test, CmpHelperFloatingPointEQ, EXPECT_EQ

#include <cmath>     // for pow, exp
#include <cstddef>   // for size_t
#include <string>    // for string
#include <vector>    // for vector

#include "buckinghamPair.hpp"   // for BuckinghamPair
#include "gtest/gtest.h"        // for AssertionResult, Message, TestPartResult
#include "nonCoulombPair.hpp"   // for potential

using namespace potential;

/**
 * @brief tests the equals operator of BuckinghamPair
 *
 */
TEST(TestBuckinghamPair, equalsOperator)
{
    const size_t vdwType1 = 0;
    const size_t vdwType2 = 1;
    const size_t vdwType3 = 2;
    const auto   nonCoulombPair1 =
        BuckinghamPair(vdwType1, vdwType2, 1.0, 2.0, 3.0, 4.0);

    const auto nonCoulombPair2 =
        BuckinghamPair(vdwType1, vdwType2, 1.0, 2.0, 3.0, 4.0);
    EXPECT_TRUE(nonCoulombPair1 == nonCoulombPair2);

    const auto nonCoulombPair3 =
        BuckinghamPair(vdwType2, vdwType1, 1.0, 2.0, 3.0, 4.0);
    EXPECT_TRUE(nonCoulombPair1 == nonCoulombPair3);

    const auto nonCoulombPair4 =
        BuckinghamPair(vdwType1, vdwType3, 1.0, 2.0, 3.0, 4.0);
    EXPECT_FALSE(nonCoulombPair1 == nonCoulombPair4);

    const auto nonCoulombPair5 =
        BuckinghamPair(vdwType1, vdwType2, 2.0, 2.0, 3.0, 4.0);
    EXPECT_FALSE(nonCoulombPair1 == nonCoulombPair5);

    const auto nonCoulombPair6 =
        BuckinghamPair(vdwType1, vdwType2, 1.0, 3.0, 3.0, 4.0);
    EXPECT_FALSE(nonCoulombPair1 == nonCoulombPair6);

    const auto nonCoulombPair7 =
        BuckinghamPair(vdwType1, vdwType2, 1.0, 2.0, 4.0, 4.0);
    EXPECT_FALSE(nonCoulombPair1 == nonCoulombPair7);

    const auto nonCoulombPair8 =
        BuckinghamPair(vdwType1, vdwType2, 1.0, 2.0, 3.0, 5.0);
    EXPECT_FALSE(nonCoulombPair1 == nonCoulombPair8);
}

/**
 * @brief tests the calculation of the energy and force of a BuckinghamPair
 *
 */
TEST(TestBuckinghamPair, calculateEnergyAndForces)
{
    const auto   coefficients = std::vector<double>{2.0, 4.0, 3.0};
    const auto   rncCutoff    = 3.0;
    const double energyCutoff = 1.0;
    const double forceCutoff  = 2.0;

    const auto potential = potential::BuckinghamPair(
        rncCutoff,
        energyCutoff,
        forceCutoff,
        coefficients[0],
        coefficients[1],
        coefficients[2]
    );

    auto distance        = 2.0;
    auto [energy, force] = potential.calculateEnergyAndForce(distance);

    auto helper = coefficients[0] * ::exp(coefficients[1] * distance);

    EXPECT_DOUBLE_EQ(
        energy,
        helper + coefficients[2] / ::pow(distance, 6) - energyCutoff -
            forceCutoff * (rncCutoff - distance)
    );
    EXPECT_DOUBLE_EQ(
        force,
        -helper * coefficients[1] + 6.0 * coefficients[2] / ::pow(distance, 7) -
            forceCutoff
    );
}