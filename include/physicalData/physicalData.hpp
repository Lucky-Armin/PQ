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

#ifndef _PHYSICAL_DATA_HPP_

#define _PHYSICAL_DATA_HPP_

#include <functional>   // for _Bind_front_t, bind_front, function
#include <vector>       // for vector

#include "staticMatrix3x3.hpp"   // for StaticMatrix3x3
#include "timer.hpp"             // for Timer
#include "vector3d.hpp"          // for Vec3D

namespace simulationBox
{
    class SimulationBox;   // forward declaration
}

namespace physicalData
{
    class PhysicalData;   // forward declaration

    PhysicalData mean(std::vector<PhysicalData> &physicalDataVector);

    /**
     * @class PhysicalData
     *
     * @brief PhysicalData is a class for output data storage
     *
     */
    class PhysicalData : public timings::Timer
    {
       private:
        double _numberOfQMAtoms = 0.0;
        double _loopTime        = 0.0;

        double _volume      = 0.0;
        double _density     = 0.0;
        double _temperature = 0.0;
        double _pressure    = 0.0;

        double _kineticEnergy         = 0.0;
        double _coulombEnergy         = 0.0;
        double _nonCoulombEnergy      = 0.0;
        double _intraCoulombEnergy    = 0.0;
        double _intraNonCoulombEnergy = 0.0;

        double _bondEnergy     = 0.0;
        double _angleEnergy    = 0.0;
        double _dihedralEnergy = 0.0;
        double _improperEnergy = 0.0;

        double _qmEnergy = 0.0;

        double _noseHooverMomentumEnergy = 0.0;
        double _noseHooverFrictionEnergy = 0.0;

        double _lowerDistanceConstraints = 0.0;
        double _upperDistanceConstraints = 0.0;

        linearAlgebra::Vec3D    _momentum                     = {0.0, 0.0, 0.0};
        linearAlgebra::Vec3D    _angularMomentum              = {0.0, 0.0, 0.0};
        linearAlgebra::tensor3D _kineticEnergyAtomicTensor    = {0.0};
        linearAlgebra::tensor3D _kineticEnergyMolecularTensor = {0.0};

        linearAlgebra::tensor3D _virial       = {0.0};
        linearAlgebra::tensor3D _stressTensor = {0.0};

        double _ringPolymerEnergy = 0.0;

       public:
        void calculateTemperature(simulationBox::SimulationBox &);
        void calculateKinetics(simulationBox::SimulationBox &);
        void changeKineticVirialToAtomic();

        std::function<linearAlgebra::StaticMatrix3x3<double>()>
            getKineticEnergyVirialVector = std::bind_front(
                &PhysicalData::getKineticEnergyMolecularVector,
                this
            );

        void updateAverages(const PhysicalData &);
        void makeAverages(const double);
        void reset();

        void addIntraCoulombEnergy(const double intraCoulombEnergy);
        void addIntraNonCoulombEnergy(const double intraNonCoulombEnergy);

        [[nodiscard]] double getTotalEnergy() const;

        /********************
         * standard adders  *
         ********************/

        void addVirial(const linearAlgebra::tensor3D &virial)
        {
            _virial += virial;
        }

        void addCoulombEnergy(const double coulombEnergy)
        {
            _coulombEnergy += coulombEnergy;
        }
        void addNonCoulombEnergy(const double nonCoulombEnergy)
        {
            _nonCoulombEnergy += nonCoulombEnergy;
        }

        void addBondEnergy(const double bondEnergy)
        {
            _bondEnergy += bondEnergy;
        }
        void addAngleEnergy(const double angleEnergy)
        {
            _angleEnergy += angleEnergy;
        }
        void addDihedralEnergy(const double dihedralEnergy)
        {
            _dihedralEnergy += dihedralEnergy;
        }
        void addImproperEnergy(const double improperEnergy)
        {
            _improperEnergy += improperEnergy;
        }

        void addRingPolymerEnergy(const double ringPolymerEnergy)
        {
            _ringPolymerEnergy += ringPolymerEnergy;
        }

        /********************
         * standard setters *
         ********************/

        void setNumberOfQMAtoms(const double nQMAtoms)
        {
            _numberOfQMAtoms = nQMAtoms;
        }

        void setLoopTime(const double loopTime) { _loopTime = loopTime; }

        void setVolume(const double volume) { _volume = volume; }
        void setDensity(const double density) { _density = density; }
        void setTemperature(const double temperature)
        {
            _temperature = temperature;
        }
        void setPressure(const double pressure) { _pressure = pressure; }

        void setVirial(const linearAlgebra::tensor3D &virial)
        {
            _virial = virial;
        }
        void setStressTensor(const linearAlgebra::tensor3D &stressTensor)
        {
            _stressTensor = stressTensor;
        }

        void setMomentum(const linearAlgebra::Vec3D &vec) { _momentum = vec; }
        void setAngularMomentum(const linearAlgebra::Vec3D &vec)
        {
            _angularMomentum = vec;
        }

        void setKineticEnergy(const double kineticEnergy)
        {
            _kineticEnergy = kineticEnergy;
        }
        void setKineticEnergyAtomicVector(const linearAlgebra::tensor3D &vec)
        {
            _kineticEnergyAtomicTensor = vec;
        }
        void setKineticEnergyMolecularVector(const linearAlgebra::tensor3D &vec)
        {
            _kineticEnergyMolecularTensor = vec;
        }

        void setCoulombEnergy(const double coulombEnergy)
        {
            _coulombEnergy = coulombEnergy;
        }
        void setNonCoulombEnergy(const double nonCoulombEnergy)
        {
            _nonCoulombEnergy = nonCoulombEnergy;
        }
        void setIntraCoulombEnergy(const double intraCoulombEnergy)
        {
            _intraCoulombEnergy = intraCoulombEnergy;
        }
        void setIntraNonCoulombEnergy(const double intraNonCoulombEnergy)
        {
            _intraNonCoulombEnergy = intraNonCoulombEnergy;
        }

        void setBondEnergy(const double bondEnergy)
        {
            _bondEnergy = bondEnergy;
        }
        void setAngleEnergy(const double angleEnergy)
        {
            _angleEnergy = angleEnergy;
        }
        void setDihedralEnergy(const double dihedralEnergy)
        {
            _dihedralEnergy = dihedralEnergy;
        }
        void setImproperEnergy(const double improperEnergy)
        {
            _improperEnergy = improperEnergy;
        }

        void setQMEnergy(const double qmEnergy) { _qmEnergy = qmEnergy; }

        void setNoseHooverMomentumEnergy(const double momentumEnergy)
        {
            _noseHooverMomentumEnergy = momentumEnergy;
        }
        void setNoseHooverFrictionEnergy(const double frictionEnergy)
        {
            _noseHooverFrictionEnergy = frictionEnergy;
        }

        void setLowerDistanceConstraints(const double lowerDistanceConstraints)
        {
            _lowerDistanceConstraints = lowerDistanceConstraints;
        }
        void setUpperDistanceConstraints(const double upperDistanceConstraints)
        {
            _upperDistanceConstraints = upperDistanceConstraints;
        }

        void setRingPolymerEnergy(const double ringPolymerEnergy) { _ringPolymerEnergy = ringPolymerEnergy; }

        /********************
         * standard getters *
         ********************/

        [[nodiscard]] double getNumberOfQMAtoms() const
        {
            return _numberOfQMAtoms;
        }

        [[nodiscard]] double getLoopTime() const { return _loopTime; }

        [[nodiscard]] double getVolume() const { return _volume; }
        [[nodiscard]] double getDensity() const { return _density; }
        [[nodiscard]] double getTemperature() const { return _temperature; }
        [[nodiscard]] double getPressure() const { return _pressure; }

        [[nodiscard]] double getKineticEnergy() const { return _kineticEnergy; }
        [[nodiscard]] double getNonCoulombEnergy() const
        {
            return _nonCoulombEnergy;
        }
        [[nodiscard]] double getCoulombEnergy() const { return _coulombEnergy; }
        [[nodiscard]] double getIntraCoulombEnergy() const
        {
            return _intraCoulombEnergy;
        }
        [[nodiscard]] double getIntraNonCoulombEnergy() const
        {
            return _intraNonCoulombEnergy;
        }
        [[nodiscard]] double getIntraEnergy() const
        {
            return _intraCoulombEnergy + _intraNonCoulombEnergy;
        }

        [[nodiscard]] double getBondEnergy() const { return _bondEnergy; }
        [[nodiscard]] double getAngleEnergy() const { return _angleEnergy; }
        [[nodiscard]] double getDihedralEnergy() const
        {
            return _dihedralEnergy;
        }
        [[nodiscard]] double getImproperEnergy() const
        {
            return _improperEnergy;
        }

        [[nodiscard]] double getQMEnergy() const { return _qmEnergy; }

        [[nodiscard]] double getNoseHooverMomentumEnergy() const
        {
            return _noseHooverMomentumEnergy;
        }
        [[nodiscard]] double getNoseHooverFrictionEnergy() const
        {
            return _noseHooverFrictionEnergy;
        }

        [[nodiscard]] double getLowerDistanceConstraints() const { return _lowerDistanceConstraints; }
        [[nodiscard]] double getUpperDistanceConstraints() const { return _upperDistanceConstraints; }

        [[nodiscard]] double getRingPolymerEnergy() const { return _ringPolymerEnergy; }

        [[nodiscard]] linearAlgebra::tensor3D getKineticEnergyAtomicVector(
        ) const
        {
            return _kineticEnergyAtomicTensor;
        }
        [[nodiscard]] linearAlgebra::tensor3D getKineticEnergyMolecularVector(
        ) const
        {
            return _kineticEnergyMolecularTensor;
        }
        [[nodiscard]] linearAlgebra::tensor3D getVirial() const
        {
            return _virial;
        }
        [[nodiscard]] linearAlgebra::tensor3D getStressTensor() const
        {
            return _stressTensor;
        }
        [[nodiscard]] linearAlgebra::Vec3D getMomentum() const
        {
            return _momentum;
        }
        [[nodiscard]] linearAlgebra::Vec3D getAngularMomentum() const
        {
            return _angularMomentum;
        }
    };

}   // namespace physicalData

#endif   // _PHYSICAL_DATA_HPP_
