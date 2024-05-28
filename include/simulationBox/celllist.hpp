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

#ifndef _CELL_LIST_HPP_

#define _CELL_LIST_HPP_

#include <cstddef>   // for size_t
#include <vector>    // for vector

#include "cell.hpp"       // for Cell
#include "defaults.hpp"   // for _NUMBER_OF_CELLS_DEFAULT_, _CELL_LIST_IS_ACT...
#include "timer.hpp"      // for Timer
#include "vector3d.hpp"   // for Vec3Dul, Vec3D

namespace simulationBox
{
    class SimulationBox;   // forward declaration

    /**
     * @class CellList
     *
     * @brief CellList is a class for cell list
     *
     */
    class CellList : public timings::Timer
    {
       private:
        bool _activated = defaults::_CELL_LIST_IS_ACTIVE_DEFAULT_;

        std::vector<Cell> _cells;

        linearAlgebra::Vec3D   _cellSize;
        linearAlgebra::Vec3Dul _nNeighbourCells{0, 0, 0};
        linearAlgebra::Vec3Dul _nCells{defaults::_NUMBER_OF_CELLS_DEFAULT_
        };   // 7x7x7

       public:
        void setup(const SimulationBox &);
        void updateCellList(SimulationBox &);

        void determineCellSize(const linearAlgebra::Vec3D &box);
        void determineCellBoundaries(const linearAlgebra::Vec3D &box);
        void checkCoulombCutoff(const double coulombCutoff) const;

        void addNeighbouringCells(const double coulombCutoff);
        void addNeighbouringCellPointers(Cell &);
        void addMoleculesToCells(SimulationBox &simulationBox);

        [[nodiscard]] size_t getCellIndex(
            const linearAlgebra::Vec3Dul &cellIndices
        ) const;
        [[nodiscard]] linearAlgebra::Vec3Dul getCellIndexOfAtom(
            const linearAlgebra::Vec3D &box,
            const linearAlgebra::Vec3D &position
        ) const;

        void resizeCells() { _cells.resize(prod(_nCells)); }
        void addCell(const Cell &cell) { _cells.push_back(cell); }

        /*****************************
         * standard activate methods *
         *****************************/

        void               activate() { _activated = true; }
        void               deactivate() { _activated = false; }
        [[nodiscard]] bool isActive() const { return _activated; }

        /***************************
         * standard getter methods *
         ***************************/

        [[nodiscard]] linearAlgebra::Vec3Dul getNumberOfCells() const
        {
            return _nCells;
        }
        [[nodiscard]] linearAlgebra::Vec3Dul getNumberOfNeighbourCells() const
        {
            return _nNeighbourCells;
        }
        [[nodiscard]] linearAlgebra::Vec3D getCellSize() const
        {
            return _cellSize;
        }
        [[nodiscard]] std::vector<Cell> getCells() const { return _cells; }
        [[nodiscard]] Cell             &getCell(const size_t index)
        {
            return _cells[index];
        }

        /***************************
         * standard setter methods *
         ***************************/

        void setNumberOfCells(const size_t nCells)
        {
            _nCells = {nCells, nCells, nCells};
        }
        void setNumberOfNeighbourCells(const size_t nCells)
        {
            _nNeighbourCells = linearAlgebra::Vec3Dul(nCells);
        }
    };

}   // namespace simulationBox

#endif   // _CELL_LIST_HPP_