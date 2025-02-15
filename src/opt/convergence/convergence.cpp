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

#include "convergence.hpp"

#include "convergenceSettings.hpp"

using namespace opt;
using namespace settings;

/**
 * @brief Construct a new Convergence object
 *
 * @param absEnergyConv
 * @param relEnergyConv
 * @param absMaxForceConv
 * @param absEnergyConvThreshold
 * @param relEnergyConvThreshold
 * @param absMaxForceConvThreshold
 * @param absRMSForceConvThreshold
 * @param energyConvStrategy
 */
Convergence::Convergence(
    const bool         _enableEnergyConv,
    const bool         _enableMaxForceConv,
    const bool         _enableRMSForceConv,
    const double       relEnergyConvThreshold,
    const double       absEnergyConvThreshold,
    const double       absMaxForceConvThreshold,
    const double       absRMSForceConvThreshold,
    const ConvStrategy energyConvStrategy
)
    : _enableEnergyConv(_enableEnergyConv),
      _enableMaxForceConv(_enableMaxForceConv),
      _enableRMSForceConv(_enableRMSForceConv),
      _relEnergyConvThreshold(relEnergyConvThreshold),
      _absEnergyConvThreshold(absEnergyConvThreshold),
      _absMaxForceConvThreshold(absMaxForceConvThreshold),
      _absRMSForceConvThreshold(absRMSForceConvThreshold),
      _energyConvStrategy(energyConvStrategy)
{
}

/**
 * @brief check if the optimizer has converged
 *
 * @return true/false if the optimizer has converged
 */
bool Convergence::checkConvergence() const
{
    auto isEnergyConverged = true;

    switch (_energyConvStrategy)
    {
        using enum ConvStrategy;

        case RIGOROUS:
            isEnergyConverged = _isAbsEnergyConv && _isRelEnergyConv;
            break;

        case LOOSE:
            isEnergyConverged = _isAbsEnergyConv || _isRelEnergyConv;
            break;

        case ABSOLUTE: isEnergyConverged = _isAbsEnergyConv; break;

        case RELATIVE: isEnergyConverged = _isRelEnergyConv; break;

        default: break;
    }

    return isEnergyConverged && _isAbsMaxForceConv && _isAbsRMSForceConv;
}

/**
 * @brief calculate the energy convergence
 *
 * @param energyOld
 * @param energyNew
 */
void Convergence::calcEnergyConvergence(
    const double energyOld,
    const double energyNew
)
{
    _absEnergy = std::abs(energyNew - energyOld);
    _relEnergy = _absEnergy / std::abs(energyOld);

    if (_enableEnergyConv)
    {
        _isAbsEnergyConv = _absEnergy < _absEnergyConvThreshold;
        _isRelEnergyConv = _relEnergy < _relEnergyConvThreshold;
    }
}

/**
 * @brief calculate the force convergence
 *
 * @param forceOld
 * @param forceNew
 */
void Convergence::calcForceConvergence(
    const double maxForce,
    const double rmsForce
)
{
    _absMaxForce = std::abs(maxForce);
    _absRMSForce = std::abs(rmsForce);

    if (_enableMaxForceConv)
        _isAbsMaxForceConv = _absMaxForce < _absMaxForceConvThreshold;

    if (_enableRMSForceConv)
        _isAbsRMSForceConv = _absRMSForce < _absRMSForceConvThreshold;
}

/***************************
 *                         *
 * standard getter methods *
 *                         *
 ***************************/

/**
 * @brief get relative energy difference
 *
 * @return double
 */
double Convergence::getRelEnergy() const { return _relEnergy; }

/**
 * @brief get absolute energy difference
 *
 * @return double
 */
double Convergence::getAbsEnergy() const { return _absEnergy; }

/**
 * @brief get absolute maximum force
 *
 * @return double
 */
double Convergence::getAbsMaxForce() const { return _absMaxForce; }

/**
 * @brief get absolute RMS force
 *
 * @return double
 */
double Convergence::getAbsRMSForce() const { return _absRMSForce; }

/**
 * @brief get energy convergence strategy
 *
 * @return ConvStrategy
 */
ConvStrategy Convergence::getEnConvStrategy() const
{
    return _energyConvStrategy;
}

/**
 * @brief get if energy convergence is enabled
 *
 * @return double
 */
bool Convergence::isEnergyConvEnabled() const { return _enableEnergyConv; }

/**
 * @brief get if maximum force convergence is enabled
 *
 * @return double
 */
bool Convergence::isMaxForceConvEnabled() const { return _enableMaxForceConv; }

/**
 * @brief get if RMS force convergence is enabled
 *
 * @return double
 */
bool Convergence::isRMSForceConvEnabled() const { return _enableRMSForceConv; }

/**
 * @brief get if relative energy convergence is achieved
 *
 * @return true
 * @return false
 */
bool Convergence::isRelEnergyConv() const { return _isRelEnergyConv; }

/**
 * @brief get if absolute energy convergence is achieved
 *
 * @return true
 * @return false
 */
bool Convergence::isAbsEnergyConv() const { return _isAbsEnergyConv; }

/**
 * @brief get if absolute maximum force convergence is achieved
 *
 * @return true
 * @return false
 */
bool Convergence::isAbsMaxForceConv() const { return _isAbsMaxForceConv; }

/**
 * @brief get if absolute RMS force convergence is achieved
 *
 * @return true
 * @return false
 */
bool Convergence::isAbsRMSForceConv() const { return _isAbsRMSForceConv; }

/**
 * @brief get the relative energy convergence threshold
 *
 * @return double
 */
double Convergence::getRelEnergyConvThreshold() const
{
    return _relEnergyConvThreshold;
}

/**
 * @brief get the absolute energy convergence threshold
 *
 * @return double
 */
double Convergence::getAbsEnergyConvThreshold() const
{
    return _absEnergyConvThreshold;
}

/**
 * @brief get the absolute maximum force convergence threshold
 *
 * @return double
 */
double Convergence::getAbsMaxForceConvThreshold() const
{
    return _absMaxForceConvThreshold;
}

/**
 * @brief get the absolute RMS force convergence threshold
 *
 * @return double
 */
double Convergence::getAbsRMSForceConvThreshold() const
{
    return _absRMSForceConvThreshold;
}