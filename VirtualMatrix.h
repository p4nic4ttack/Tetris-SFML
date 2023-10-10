#ifndef VIRTUALMATRIX_H
#define VIRTUALMATRIX_H
#include <array>
#include "Position.h"

class Movable;

class VirtualMatrix
{
private:
	typedef std::array<std::array<bool, 10>, 20> VirtMatrix;
	VirtMatrix m_virtMatrix;
public:
	VirtualMatrix();
	bool setBlock(const Position&);
	bool checkOccupied(int, int);
	bool checkOccupied(const Position&);
	bool checkRowComplete(int);
	void updateMatrix(Movable&);
	void clearCompletedRow(int);
	void dropCellsIfHigher(int);
	VirtMatrix getMatrix();
	void printMatrix();
	void lowerAllBlocksAboveRow(int);
};

#endif