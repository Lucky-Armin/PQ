#ifndef _CELL_LIST_H_

#define _CELL_LIST_H_

#include <vector>

#include "cell.hpp"
#include "simulationBox.hpp"

/**
 * @class CellList
 *
 * @brief CellList is a class for cell list
 *
 */
class CellList
{
private:
    std::vector<Cell> _cells;

    bool _activated = false;

    int _nCellsX = 7;
    int _nCellsY = 7;
    int _nCellsZ = 7;

    int _nNeighbourCellsX;
    int _nNeighbourCellsY;
    int _nNeighbourCellsZ;

    std::vector<double> _cellSize;

public:
    // void setCells(Cell &cell, int index_x, int index_y, int index_z);
    Cell &getCell(int index) { return _cells[index]; }
    std::vector<Cell> getCells() const { return _cells; }

    void activate() { _activated = true; }
    bool isActivated() const { return _activated; }

    void setNumberOfCells(int nCells)
    {
        _nCellsX = nCells;
        _nCellsY = nCells;
        _nCellsZ = nCells;
    }

    std::vector<double> getCellSize() const { return _cellSize; }

    void setup(SimulationBox &);
    void determineCellSize(SimulationBox &);
    void determineCellBoundaries(SimulationBox &);
    void addNeighbouringCells(SimulationBox &);
    void addCellPointers(Cell &);
    void updateCellList(SimulationBox &);
    std::vector<int> getCellIndexOfMolecule(const SimulationBox &, const std::vector<double> &);
    int getCellIndex(const std::vector<int> &cellIndices)
    {
        return cellIndices[0] * _nCellsY * _nCellsZ + cellIndices[1] * _nCellsZ + cellIndices[2];
    }
};

#endif // _CELL_LIST_H_