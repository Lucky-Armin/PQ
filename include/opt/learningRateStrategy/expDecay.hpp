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

#ifndef _EXP_DECAY_HPP_

#define _EXP_DECAY_HPP_

#include <cmath>   // for exp

#include "learningRateStrategy.hpp"

namespace opt
{
    /**
     * @brief Exponential decay learning rate strategy
     *
     */
    class ExpDecayLR : public LearningRateStrategy
    {
       private:
        double _decay;

       public:
        ExpDecayLR() = default;
        ExpDecayLR(const double, const double, const size_t);

        std::shared_ptr<LearningRateStrategy> clone() const override;

        void updateLearningRate(const size_t, const size_t) override;
    };

}   // namespace opt

#endif   // _EXP_DECAY_HPP_