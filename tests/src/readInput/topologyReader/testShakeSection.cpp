#include "bondConstraint.hpp"        // for BondConstraint
#include "constraints.hpp"           // for Constraints
#include "engine.hpp"                // for Engine
#include "exceptions.hpp"            // for TopologyException
#include "shakeSection.hpp"          // for ShakeSection
#include "simulationBox.hpp"         // for SimulationBox
#include "testTopologySection.hpp"   // for TestTopologySection

#include "gtest/gtest.h"   // for Message, TestPartResult
#include <gtest/gtest.h>   // for EXPECT_EQ, TestInfo (ptr only)
#include <string>          // for string, allocator, basic_string
#include <vector>          // for vector

/**
 * @brief test shake section processing one line
 *
 */
TEST_F(TestTopologySection, processSectionShake)
{
    std::vector<std::string>          lineElements = {"1", "2", "1.0", "0"};
    readInput::topology::ShakeSection shakeSection;
    shakeSection.processSection(lineElements, *_engine);
    EXPECT_EQ(_engine->getConstraints().getBondConstraints().size(), 1);
    EXPECT_EQ(_engine->getConstraints().getBondConstraints()[0].getMolecule1(), &(_engine->getSimulationBox().getMolecules()[0]));
    EXPECT_EQ(_engine->getConstraints().getBondConstraints()[0].getMolecule2(), &(_engine->getSimulationBox().getMolecules()[1]));
    EXPECT_EQ(_engine->getConstraints().getBondConstraints()[0].getAtomIndex1(), 0);
    EXPECT_EQ(_engine->getConstraints().getBondConstraints()[0].getAtomIndex2(), 0);
    EXPECT_EQ(_engine->getConstraints().getBondConstraints()[0].getTargetBondLength(), 1.0);

    lineElements = {"1", "1", "1.0", "0"};
    EXPECT_THROW(shakeSection.processSection(lineElements, *_engine), customException::TopologyException);

    lineElements = {"1", "1", "1.0", "0", "1"};
    EXPECT_THROW(shakeSection.processSection(lineElements, *_engine), customException::TopologyException);
}

/**
 * @brief test if endedNormally throws exception
 *
 */
TEST_F(TestTopologySection, endedNormallyShake)
{
    readInput::topology::ShakeSection shakeSection;
    EXPECT_THROW(shakeSection.endedNormally(false), customException::TopologyException);
    EXPECT_NO_THROW(shakeSection.endedNormally(true));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return ::RUN_ALL_TESTS();
}