#ifndef _TEST_GUFFDATREADER_HPP_

#define _TEST_GUFFDATREADER_HPP_

#include "guffDatReader.hpp"
#include "potential.hpp"

#include <gtest/gtest.h>
#include <memory>

class TestGuffDatReader : public ::testing::Test
{
  protected:
    void SetUp() override
    {
        auto molecule1 = simulationBox::Molecule();
        molecule1.setNumberOfAtoms(2);
        molecule1.setMoltype(1);
        molecule1.addExternalAtomType(1);
        molecule1.addExternalAtomType(2);
        molecule1.addExternalToInternalAtomTypeElement(1, 0);
        molecule1.addExternalToInternalAtomTypeElement(2, 1);

        auto molecule2 = simulationBox::Molecule();
        molecule2.setNumberOfAtoms(1);
        molecule2.setMoltype(2);
        molecule2.addExternalAtomType(3);
        molecule2.addExternalToInternalAtomTypeElement(3, 0);

        _engine = new engine::Engine();
        _engine->getSimulationBox().addMoleculeType(molecule1);
        _engine->getSimulationBox().addMoleculeType(molecule2);

        _engine->getSimulationBox().setRcCutOff(12.5);

        _engine->_potential = std::make_unique<potential::PotentialBruteForce>();
        _engine->_potential->setNonCoulombPotential(potential::GuffNonCoulomb());
        _engine->_potential->setCoulombPotential(potential::GuffCoulomb());

        _guffDatReader = new setup::GuffDatReader(*_engine);
    }

    void TearDown() override
    {
        delete _guffDatReader;
        delete _engine;
    }

    setup::GuffDatReader *_guffDatReader;
    engine::Engine       *_engine;
};

#endif   // _TEST_GUFFDATREADER_HPP_