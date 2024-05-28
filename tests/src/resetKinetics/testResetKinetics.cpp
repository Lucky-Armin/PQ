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

// #include "testResetKinetics.hpp"

// #include "gtest/gtest.h"   // for Message, TestPartResult
// #include <cmath>           // for sqrt
// #include <string>          // for allocator, basic_string

// /**
//  * @brief tests the resetTemperature method
//  *
//  */
// TEST_F(TestResetKinetics, resetTemperature)
// {
//     const auto velocity_mol1_atom1_old =
//     _simulationBox->getMolecule(0).getAtomVelocity(0); const auto
//     velocity_mol1_atom2_old =
//     _simulationBox->getMolecule(0).getAtomVelocity(1); const auto
//     velocity_mol2_atom1_old =
//     _simulationBox->getMolecule(1).getAtomVelocity(0);

//     _data->setTemperature(100.0);
//     _resetKinetics->resetTemperature(*_data, *_simulationBox);

//     const auto velocity_mol1_atom1_new =
//     _simulationBox->getMolecule(0).getAtomVelocity(0); const auto
//     velocity_mol1_atom2_new =
//     _simulationBox->getMolecule(0).getAtomVelocity(1); const auto
//     velocity_mol2_atom1_new =
//     _simulationBox->getMolecule(1).getAtomVelocity(0);

//     EXPECT_DOUBLE_EQ(velocity_mol1_atom1_new[0] / velocity_mol1_atom1_old[0],
//     sqrt(3.0)); EXPECT_DOUBLE_EQ(velocity_mol1_atom1_new[1] /
//     velocity_mol1_atom1_old[1], sqrt(3.0));
//     EXPECT_DOUBLE_EQ(velocity_mol1_atom1_new[2] / velocity_mol1_atom1_old[2],
//     sqrt(3.0)); EXPECT_DOUBLE_EQ(velocity_mol1_atom2_new[0] /
//     velocity_mol1_atom2_old[0], sqrt(3.0));
//     EXPECT_DOUBLE_EQ(velocity_mol1_atom2_new[1] / velocity_mol1_atom2_old[1],
//     sqrt(3.0)); EXPECT_DOUBLE_EQ(velocity_mol1_atom2_new[2] /
//     velocity_mol1_atom2_old[2], sqrt(3.0));
//     EXPECT_DOUBLE_EQ(velocity_mol2_atom1_new[0] / velocity_mol2_atom1_old[0],
//     sqrt(3.0)); EXPECT_DOUBLE_EQ(velocity_mol2_atom1_new[1] /
//     velocity_mol2_atom1_old[1], sqrt(3.0));
//     EXPECT_DOUBLE_EQ(velocity_mol2_atom1_new[2] / velocity_mol2_atom1_old[2],
//     sqrt(3.0));
// }

// /**
//  * @brief tests the resetMomentum method
//  *
//  */
// TEST_F(TestResetKinetics, resetMomentum)
// {
//     _data->setMomentum(linearAlgebra::Vec3D(1.0, 2.0, 3.0));
//     _resetKinetics->resetMomentum(*_data, *_simulationBox);

//     const auto velocity_mol1_atom1 =
//         _simulationBox->getMolecule(0).getAtomVelocity(0) -
//         linearAlgebra::Vec3D(1.0, 2.0, 3.0) / 3.0;
//     const auto velocity_mol1_atom2 =
//         _simulationBox->getMolecule(0).getAtomVelocity(1) -
//         linearAlgebra::Vec3D(1.0, 2.0, 3.0) / 3.0;
//     const auto velocity_mol2_atom1 =
//         _simulationBox->getMolecule(1).getAtomVelocity(0) -
//         linearAlgebra::Vec3D(1.0, 2.0, 3.0) / 3.0;

//     EXPECT_NEAR(_simulationBox->getMolecule(0).getAtomVelocity(0)[0],
//     velocity_mol1_atom1[0], 10.0);
//     EXPECT_NEAR(_simulationBox->getMolecule(0).getAtomVelocity(0)[1],
//     velocity_mol1_atom1[1], 10.0);
//     EXPECT_NEAR(_simulationBox->getMolecule(0).getAtomVelocity(0)[2],
//     velocity_mol1_atom1[2], 10.0);
//     EXPECT_NEAR(_simulationBox->getMolecule(0).getAtomVelocity(1)[0],
//     velocity_mol1_atom2[0], 10.0);
//     EXPECT_NEAR(_simulationBox->getMolecule(0).getAtomVelocity(1)[1],
//     velocity_mol1_atom2[1], 10.0);
//     EXPECT_NEAR(_simulationBox->getMolecule(0).getAtomVelocity(1)[2],
//     velocity_mol1_atom2[2], 10.0);
//     EXPECT_NEAR(_simulationBox->getMolecule(1).getAtomVelocity(0)[0],
//     velocity_mol2_atom1[0], 10.0);
//     EXPECT_NEAR(_simulationBox->getMolecule(1).getAtomVelocity(0)[1],
//     velocity_mol2_atom1[1], 10.0);
//     EXPECT_NEAR(_simulationBox->getMolecule(1).getAtomVelocity(0)[2],
//     velocity_mol2_atom1[2], 10.0);
// }

// /**
//  * @brief tests the reset method with no reset
//  *
//  */
// TEST_F(TestResetKinetics, noReset) {
// EXPECT_NO_THROW(_resetKinetics->reset(10, *_data, *_simulationBox)); }

// /**
//  * @brief tests the reset method with nscale
//  *
//  */
// TEST_F(TestResetKinetics, resetTemperatureNscale)
// {
//     _resetKinetics = new resetKinetics::ResetTemperature(10, 11, 0, 11, 0,
//     11);

//     const auto velocity_mol1_atom1_old =
//     _simulationBox->getMolecule(0).getAtomVelocity(0); const auto
//     velocity_mol1_atom2_old =
//     _simulationBox->getMolecule(0).getAtomVelocity(1); const auto
//     velocity_mol2_atom1_old =
//     _simulationBox->getMolecule(1).getAtomVelocity(0);

//     _data->setTemperature(100.0);

//     _resetKinetics->reset(9, *_data, *_simulationBox);

//     const auto velocity_mol1_atom1_new =
//     _simulationBox->getMolecule(0).getAtomVelocity(0); const auto
//     velocity_mol1_atom2_new =
//     _simulationBox->getMolecule(0).getAtomVelocity(1); const auto
//     velocity_mol2_atom1_new =
//     _simulationBox->getMolecule(1).getAtomVelocity(0);

//     EXPECT_NE(velocity_mol1_atom1_new[0], velocity_mol1_atom1_old[0]);
//     EXPECT_NE(velocity_mol1_atom1_new[1], velocity_mol1_atom1_old[1]);
//     EXPECT_NE(velocity_mol1_atom1_new[2], velocity_mol1_atom1_old[2]);
//     EXPECT_NE(velocity_mol1_atom2_new[0], velocity_mol1_atom2_old[0]);
//     EXPECT_NE(velocity_mol1_atom2_new[1], velocity_mol1_atom2_old[1]);
//     EXPECT_NE(velocity_mol1_atom2_new[2], velocity_mol1_atom2_old[2]);
//     EXPECT_NE(velocity_mol2_atom1_new[0], velocity_mol2_atom1_old[0]);
//     EXPECT_NE(velocity_mol2_atom1_new[1], velocity_mol2_atom1_old[1]);
//     EXPECT_NE(velocity_mol2_atom1_new[2], velocity_mol2_atom1_old[2]);

//     _resetKinetics->reset(15, *_data, *_simulationBox);

//     const auto velocity_mol1_atom1_new2 =
//     _simulationBox->getMolecule(0).getAtomVelocity(0); const auto
//     velocity_mol1_atom2_new2 =
//     _simulationBox->getMolecule(0).getAtomVelocity(1); const auto
//     velocity_mol2_atom1_new2 =
//     _simulationBox->getMolecule(1).getAtomVelocity(0);

//     EXPECT_NEAR(velocity_mol1_atom1_new2[0],
//     velocity_mol1_atom1_new[0], 10.0);
//     EXPECT_NEAR(velocity_mol1_atom1_new2[1],
//     velocity_mol1_atom1_new[1], 10.0);
//     EXPECT_NEAR(velocity_mol1_atom1_new2[2],
//     velocity_mol1_atom1_new[2], 10.0);
//     EXPECT_NEAR(velocity_mol1_atom2_new2[0],
//     velocity_mol1_atom2_new[0], 10.0);
//     EXPECT_NEAR(velocity_mol1_atom2_new2[1],
//     velocity_mol1_atom2_new[1], 10.0);
//     EXPECT_NEAR(velocity_mol1_atom2_new2[2],
//     velocity_mol1_atom2_new[2], 10.0);
//     EXPECT_NEAR(velocity_mol2_atom1_new2[0],
//     velocity_mol2_atom1_new[0], 10.0);
//     EXPECT_NEAR(velocity_mol2_atom1_new2[1],
//     velocity_mol2_atom1_new[1], 10.0);
//     EXPECT_NEAR(velocity_mol2_atom1_new2[2],
//     velocity_mol2_atom1_new[2], 10.0);
// }

// /**
//  * @brief tests the reset method with fscale
//  *
//  */
// TEST_F(TestResetKinetics, resetTemperatureFscale)
// {
//     _resetKinetics = new resetKinetics::ResetTemperature(0, 9, 0, 11, 0, 11);

//     const auto velocity_mol1_atom1_old =
//     _simulationBox->getMolecule(0).getAtomVelocity(0); const auto
//     velocity_mol1_atom2_old =
//     _simulationBox->getMolecule(0).getAtomVelocity(1); const auto
//     velocity_mol2_atom1_old =
//     _simulationBox->getMolecule(1).getAtomVelocity(0);

//     _data->setTemperature(100.0);

//     _resetKinetics->reset(9, *_data, *_simulationBox);

//     const auto velocity_mol1_atom1_new =
//     _simulationBox->getMolecule(0).getAtomVelocity(0); const auto
//     velocity_mol1_atom2_new =
//     _simulationBox->getMolecule(0).getAtomVelocity(1); const auto
//     velocity_mol2_atom1_new =
//     _simulationBox->getMolecule(1).getAtomVelocity(0);

//     EXPECT_NE(velocity_mol1_atom1_new[0], velocity_mol1_atom1_old[0]);
//     EXPECT_NE(velocity_mol1_atom1_new[1], velocity_mol1_atom1_old[1]);
//     EXPECT_NE(velocity_mol1_atom1_new[2], velocity_mol1_atom1_old[2]);
//     EXPECT_NE(velocity_mol1_atom2_new[0], velocity_mol1_atom2_old[0]);
//     EXPECT_NE(velocity_mol1_atom2_new[1], velocity_mol1_atom2_old[1]);
//     EXPECT_NE(velocity_mol1_atom2_new[2], velocity_mol1_atom2_old[2]);
//     EXPECT_NE(velocity_mol2_atom1_new[0], velocity_mol2_atom1_old[0]);
//     EXPECT_NE(velocity_mol2_atom1_new[1], velocity_mol2_atom1_old[1]);
//     EXPECT_NE(velocity_mol2_atom1_new[2], velocity_mol2_atom1_old[2]);

//     _resetKinetics->reset(15, *_data, *_simulationBox);

//     const auto velocity_mol1_atom1_new2 =
//     _simulationBox->getMolecule(0).getAtomVelocity(0); const auto
//     velocity_mol1_atom2_new2 =
//     _simulationBox->getMolecule(0).getAtomVelocity(1); const auto
//     velocity_mol2_atom1_new2 =
//     _simulationBox->getMolecule(1).getAtomVelocity(0);

//     EXPECT_NEAR(velocity_mol1_atom1_new2[0],
//     velocity_mol1_atom1_new[0], 10.0);
//     EXPECT_NEAR(velocity_mol1_atom1_new2[1],
//     velocity_mol1_atom1_new[1], 10.0);
//     EXPECT_NEAR(velocity_mol1_atom1_new2[2],
//     velocity_mol1_atom1_new[2], 10.0);
//     EXPECT_NEAR(velocity_mol1_atom2_new2[0],
//     velocity_mol1_atom2_new[0], 10.0);
//     EXPECT_NEAR(velocity_mol1_atom2_new2[1],
//     velocity_mol1_atom2_new[1], 10.0);
//     EXPECT_NEAR(velocity_mol1_atom2_new2[2],
//     velocity_mol1_atom2_new[2], 10.0);
//     EXPECT_NEAR(velocity_mol2_atom1_new2[0],
//     velocity_mol2_atom1_new[0], 10.0);
//     EXPECT_NEAR(velocity_mol2_atom1_new2[1],
//     velocity_mol2_atom1_new[1], 10.0);
//     EXPECT_NEAR(velocity_mol2_atom1_new2[2],
//     velocity_mol2_atom1_new[2], 10.0);
// }

// /**
//  * @brief tests the reset momentum method with nreset
//  *
//  */
// TEST_F(TestResetKinetics, resetMomentumNreset)
// {
//     _resetKinetics = new resetKinetics::ResetMomentum(0, 11, 10, 11, 0, 11);

//     const auto velocity_mol1_atom1_old =
//     _simulationBox->getMolecule(0).getAtomVelocity(0); const auto
//     velocity_mol1_atom2_old =
//     _simulationBox->getMolecule(0).getAtomVelocity(1); const auto
//     velocity_mol2_atom1_old =
//     _simulationBox->getMolecule(1).getAtomVelocity(0);

//     _data->setMomentum(linearAlgebra::Vec3D(1.0, 2.0, 3.0));

//     _resetKinetics->reset(9, *_data, *_simulationBox);

//     const auto velocity_mol1_atom1_new =
//     _simulationBox->getMolecule(0).getAtomVelocity(0); const auto
//     velocity_mol1_atom2_new =
//     _simulationBox->getMolecule(0).getAtomVelocity(1); const auto
//     velocity_mol2_atom1_new =
//     _simulationBox->getMolecule(1).getAtomVelocity(0);

//     EXPECT_NE(velocity_mol1_atom1_new[0], velocity_mol1_atom1_old[0]);
//     EXPECT_NE(velocity_mol1_atom1_new[1], velocity_mol1_atom1_old[1]);
//     EXPECT_NE(velocity_mol1_atom1_new[2], velocity_mol1_atom1_old[2]);
//     EXPECT_NE(velocity_mol1_atom2_new[0], velocity_mol1_atom2_old[0]);
//     EXPECT_NE(velocity_mol1_atom2_new[1], velocity_mol1_atom2_old[1]);
//     EXPECT_NE(velocity_mol1_atom2_new[2], velocity_mol1_atom2_old[2]);
//     EXPECT_NE(velocity_mol2_atom1_new[0], velocity_mol2_atom1_old[0]);
//     EXPECT_NE(velocity_mol2_atom1_new[1], velocity_mol2_atom1_old[1]);
//     EXPECT_NE(velocity_mol2_atom1_new[2], velocity_mol2_atom1_old[2]);

//     _resetKinetics->reset(15, *_data, *_simulationBox);

//     const auto velocity_mol1_atom1_new2 =
//     _simulationBox->getMolecule(0).getAtomVelocity(0); const auto
//     velocity_mol1_atom2_new2 =
//     _simulationBox->getMolecule(0).getAtomVelocity(1); const auto
//     velocity_mol2_atom1_new2 =
//     _simulationBox->getMolecule(1).getAtomVelocity(0);

//     EXPECT_NEAR(velocity_mol1_atom1_new2[0],
//     velocity_mol1_atom1_new[0], 10.0);
//     EXPECT_NEAR(velocity_mol1_atom1_new2[1],
//     velocity_mol1_atom1_new[1], 10.0);
//     EXPECT_NEAR(velocity_mol1_atom1_new2[2],
//     velocity_mol1_atom1_new[2], 10.0);
//     EXPECT_NEAR(velocity_mol1_atom2_new2[0],
//     velocity_mol1_atom2_new[0], 10.0);
//     EXPECT_NEAR(velocity_mol1_atom2_new2[1],
//     velocity_mol1_atom2_new[1], 10.0);
//     EXPECT_NEAR(velocity_mol1_atom2_new2[2],
//     velocity_mol1_atom2_new[2], 10.0);
//     EXPECT_NEAR(velocity_mol2_atom1_new2[0],
//     velocity_mol2_atom1_new[0], 10.0);
//     EXPECT_NEAR(velocity_mol2_atom1_new2[1],
//     velocity_mol2_atom1_new[1], 10.0);
//     EXPECT_NEAR(velocity_mol2_atom1_new2[2],
//     velocity_mol2_atom1_new[2], 10.0);
// }

// /**
//  * @brief tests the reset temperature method with nreset
//  *
//  */
// TEST_F(TestResetKinetics, resetTemperatureNreset)
// {
//     _resetKinetics = new resetKinetics::ResetTemperature(0, 11, 10, 11, 0,
//     11);

//     const auto velocity_mol1_atom1_old =
//     _simulationBox->getMolecule(0).getAtomVelocity(0); const auto
//     velocity_mol1_atom2_old =
//     _simulationBox->getMolecule(0).getAtomVelocity(1); const auto
//     velocity_mol2_atom1_old =
//     _simulationBox->getMolecule(1).getAtomVelocity(0);

//     _data->setMomentum(linearAlgebra::Vec3D(1.0, 2.0, 3.0));

//     _resetKinetics->reset(9, *_data, *_simulationBox);

//     const auto velocity_mol1_atom1_new =
//     _simulationBox->getMolecule(0).getAtomVelocity(0); const auto
//     velocity_mol1_atom2_new =
//     _simulationBox->getMolecule(0).getAtomVelocity(1); const auto
//     velocity_mol2_atom1_new =
//     _simulationBox->getMolecule(1).getAtomVelocity(0);

//     EXPECT_NE(velocity_mol1_atom1_new[0], velocity_mol1_atom1_old[0]);
//     EXPECT_NE(velocity_mol1_atom1_new[1], velocity_mol1_atom1_old[1]);
//     EXPECT_NE(velocity_mol1_atom1_new[2], velocity_mol1_atom1_old[2]);
//     EXPECT_NE(velocity_mol1_atom2_new[0], velocity_mol1_atom2_old[0]);
//     EXPECT_NE(velocity_mol1_atom2_new[1], velocity_mol1_atom2_old[1]);
//     EXPECT_NE(velocity_mol1_atom2_new[2], velocity_mol1_atom2_old[2]);
//     EXPECT_NE(velocity_mol2_atom1_new[0], velocity_mol2_atom1_old[0]);
//     EXPECT_NE(velocity_mol2_atom1_new[1], velocity_mol2_atom1_old[1]);
//     EXPECT_NE(velocity_mol2_atom1_new[2], velocity_mol2_atom1_old[2]);

//     _resetKinetics->reset(15, *_data, *_simulationBox);

//     const auto velocity_mol1_atom1_new2 =
//     _simulationBox->getMolecule(0).getAtomVelocity(0); const auto
//     velocity_mol1_atom2_new2 =
//     _simulationBox->getMolecule(0).getAtomVelocity(1); const auto
//     velocity_mol2_atom1_new2 =
//     _simulationBox->getMolecule(1).getAtomVelocity(0);

//     EXPECT_NEAR(velocity_mol1_atom1_new2[0],
//     velocity_mol1_atom1_new[0], 10.0);
//     EXPECT_NEAR(velocity_mol1_atom1_new2[1],
//     velocity_mol1_atom1_new[1], 10.0);
//     EXPECT_NEAR(velocity_mol1_atom1_new2[2],
//     velocity_mol1_atom1_new[2], 10.0);
//     EXPECT_NEAR(velocity_mol1_atom2_new2[0],
//     velocity_mol1_atom2_new[0], 10.0);
//     EXPECT_NEAR(velocity_mol1_atom2_new2[1],
//     velocity_mol1_atom2_new[1], 10.0);
//     EXPECT_NEAR(velocity_mol1_atom2_new2[2],
//     velocity_mol1_atom2_new[2], 10.0);
//     EXPECT_NEAR(velocity_mol2_atom1_new2[0],
//     velocity_mol2_atom1_new[0], 10.0);
//     EXPECT_NEAR(velocity_mol2_atom1_new2[1],
//     velocity_mol2_atom1_new[1], 10.0);
//     EXPECT_NEAR(velocity_mol2_atom1_new2[2],
//     velocity_mol2_atom1_new[2], 10.0);
// }

// /**
//  * @brief tests the reset temperature method with freset
//  *
//  */
// TEST_F(TestResetKinetics, resetMomentumFreset)
// {
//     _resetKinetics = new resetKinetics::ResetMomentum(0, 11, 0, 9, 0, 11);

//     const auto velocity_mol1_atom1_old =
//     _simulationBox->getMolecule(0).getAtomVelocity(0); const auto
//     velocity_mol1_atom2_old =
//     _simulationBox->getMolecule(0).getAtomVelocity(1); const auto
//     velocity_mol2_atom1_old =
//     _simulationBox->getMolecule(1).getAtomVelocity(0);

//     _data->setMomentum(linearAlgebra::Vec3D(1.0, 2.0, 3.0));

//     _resetKinetics->reset(9, *_data, *_simulationBox);

//     const auto velocity_mol1_atom1_new =
//     _simulationBox->getMolecule(0).getAtomVelocity(0); const auto
//     velocity_mol1_atom2_new =
//     _simulationBox->getMolecule(0).getAtomVelocity(1); const auto
//     velocity_mol2_atom1_new =
//     _simulationBox->getMolecule(1).getAtomVelocity(0);

//     EXPECT_NE(velocity_mol1_atom1_new[0], velocity_mol1_atom1_old[0]);
//     EXPECT_NE(velocity_mol1_atom1_new[1], velocity_mol1_atom1_old[1]);
//     EXPECT_NE(velocity_mol1_atom1_new[2], velocity_mol1_atom1_old[2]);
//     EXPECT_NE(velocity_mol1_atom2_new[0], velocity_mol1_atom2_old[0]);
//     EXPECT_NE(velocity_mol1_atom2_new[1], velocity_mol1_atom2_old[1]);
//     EXPECT_NE(velocity_mol1_atom2_new[2], velocity_mol1_atom2_old[2]);
//     EXPECT_NE(velocity_mol2_atom1_new[0], velocity_mol2_atom1_old[0]);
//     EXPECT_NE(velocity_mol2_atom1_new[1], velocity_mol2_atom1_old[1]);
//     EXPECT_NE(velocity_mol2_atom1_new[2], velocity_mol2_atom1_old[2]);

//     _resetKinetics->reset(15, *_data, *_simulationBox);

//     const auto velocity_mol1_atom1_new2 =
//     _simulationBox->getMolecule(0).getAtomVelocity(0); const auto
//     velocity_mol1_atom2_new2 =
//     _simulationBox->getMolecule(0).getAtomVelocity(1); const auto
//     velocity_mol2_atom1_new2 =
//     _simulationBox->getMolecule(1).getAtomVelocity(0);

//     EXPECT_NEAR(velocity_mol1_atom1_new2[0],
//     velocity_mol1_atom1_new[0], 10.0);
//     EXPECT_NEAR(velocity_mol1_atom1_new2[1],
//     velocity_mol1_atom1_new[1], 10.0);
//     EXPECT_NEAR(velocity_mol1_atom1_new2[2],
//     velocity_mol1_atom1_new[2], 10.0);
//     EXPECT_NEAR(velocity_mol1_atom2_new2[0],
//     velocity_mol1_atom2_new[0], 10.0);
//     EXPECT_NEAR(velocity_mol1_atom2_new2[1],
//     velocity_mol1_atom2_new[1], 10.0);
//     EXPECT_NEAR(velocity_mol1_atom2_new2[2],
//     velocity_mol1_atom2_new[2], 10.0);
//     EXPECT_NEAR(velocity_mol2_atom1_new2[0],
//     velocity_mol2_atom1_new[0], 10.0);
//     EXPECT_NEAR(velocity_mol2_atom1_new2[1],
//     velocity_mol2_atom1_new[1], 10.0);
//     EXPECT_NEAR(velocity_mol2_atom1_new2[2],
//     velocity_mol2_atom1_new[2], 10.0);
// }

// /**
//  * @brief tests the reset temperature method with freset
//  *
//  */
// TEST_F(TestResetKinetics, resetTemperatureFreset)
// {
//     _resetKinetics = new resetKinetics::ResetTemperature(0, 11, 0, 9, 0, 11);

//     const auto velocity_mol1_atom1_old =
//     _simulationBox->getMolecule(0).getAtomVelocity(0); const auto
//     velocity_mol1_atom2_old =
//     _simulationBox->getMolecule(0).getAtomVelocity(1); const auto
//     velocity_mol2_atom1_old =
//     _simulationBox->getMolecule(1).getAtomVelocity(0);

//     _data->setMomentum(linearAlgebra::Vec3D(1.0, 2.0, 3.0));

//     _resetKinetics->reset(9, *_data, *_simulationBox);

//     const auto velocity_mol1_atom1_new =
//     _simulationBox->getMolecule(0).getAtomVelocity(0); const auto
//     velocity_mol1_atom2_new =
//     _simulationBox->getMolecule(0).getAtomVelocity(1); const auto
//     velocity_mol2_atom1_new =
//     _simulationBox->getMolecule(1).getAtomVelocity(0);

//     EXPECT_NE(velocity_mol1_atom1_new[0], velocity_mol1_atom1_old[0]);
//     EXPECT_NE(velocity_mol1_atom1_new[1], velocity_mol1_atom1_old[1]);
//     EXPECT_NE(velocity_mol1_atom1_new[2], velocity_mol1_atom1_old[2]);
//     EXPECT_NE(velocity_mol1_atom2_new[0], velocity_mol1_atom2_old[0]);
//     EXPECT_NE(velocity_mol1_atom2_new[1], velocity_mol1_atom2_old[1]);
//     EXPECT_NE(velocity_mol1_atom2_new[2], velocity_mol1_atom2_old[2]);
//     EXPECT_NE(velocity_mol2_atom1_new[0], velocity_mol2_atom1_old[0]);
//     EXPECT_NE(velocity_mol2_atom1_new[1], velocity_mol2_atom1_old[1]);
//     EXPECT_NE(velocity_mol2_atom1_new[2], velocity_mol2_atom1_old[2]);

//     _resetKinetics->reset(15, *_data, *_simulationBox);

//     const auto velocity_mol1_atom1_new2 =
//     _simulationBox->getMolecule(0).getAtomVelocity(0); const auto
//     velocity_mol1_atom2_new2 =
//     _simulationBox->getMolecule(0).getAtomVelocity(1); const auto
//     velocity_mol2_atom1_new2 =
//     _simulationBox->getMolecule(1).getAtomVelocity(0);

//     EXPECT_NEAR(velocity_mol1_atom1_new2[0],
//     velocity_mol1_atom1_new[0], 10.0);
//     EXPECT_NEAR(velocity_mol1_atom1_new2[1],
//     velocity_mol1_atom1_new[1], 10.0);
//     EXPECT_NEAR(velocity_mol1_atom1_new2[2],
//     velocity_mol1_atom1_new[2], 10.0);
//     EXPECT_NEAR(velocity_mol1_atom2_new2[0],
//     velocity_mol1_atom2_new[0], 10.0);
//     EXPECT_NEAR(velocity_mol1_atom2_new2[1],
//     velocity_mol1_atom2_new[1], 10.0);
//     EXPECT_NEAR(velocity_mol1_atom2_new2[2],
//     velocity_mol1_atom2_new[2], 10.0);
//     EXPECT_NEAR(velocity_mol2_atom1_new2[0],
//     velocity_mol2_atom1_new[0], 10.0);
//     EXPECT_NEAR(velocity_mol2_atom1_new2[1],
//     velocity_mol2_atom1_new[1], 10.0);
//     EXPECT_NEAR(velocity_mol2_atom1_new2[2],
//     velocity_mol2_atom1_new[2], 10.0);
// }