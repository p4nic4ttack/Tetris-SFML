#include "VirtualMatrix.h"
#include <iostream>
#include <math.h>
#include <cassert>
#include "Movable.h"

VirtualMatrix::VirtualMatrix()
{
	for (int row = 0; row != m_virtMatrix.size(); row++) {
		m_virtMatrix.at(row).fill(false);
	}
}


//returns false when game over
bool VirtualMatrix::setBlock(const Position &pos)
{
	float x = (float)pos.getX();
	float y = (float)pos.getY();

	float row = y / 35;
	float col = x / 35;
	std::cout << "Row: " << row << "\n";
	if(row < 0.5){
		return false;
	}
	m_virtMatrix.at(round(row)).at(round(col)) = true;
	return true;
}

bool VirtualMatrix::checkOccupied(int row, int col)
{
	return m_virtMatrix.at(row).at(col);
}

bool VirtualMatrix::checkOccupied(const Position &pos)
{
	float x = (float)pos.getX();
	float y = (float)pos.getY();

	float row = y / 35;
	float col = x / 35;

	if (row < 0)
		row = 0;
	if (row > 19)
		row = 19;
	if (col < 0)
		col = 0;
	if (col > 9)
		col = 9;

	return m_virtMatrix.at(round(row)).at(round(col));
}

bool VirtualMatrix::checkRowComplete(int row)
{
	assert(row >= 0 && row <= 19 && "Row is not between 0 and 19");
	for (int col = 0; col != m_virtMatrix.at(row).size(); col++) {
		if (!m_virtMatrix.at(row).at(col)) {
			return false;
		}
	}
	return true;
}

void VirtualMatrix::updateMatrix(Movable &blockComposition)
{
	for (auto &block : blockComposition.getBlockArray()) {
		setBlock(block.getCell().getPosition());
	}
}

void VirtualMatrix::clearCompletedRow(int row)
{
	m_virtMatrix.at(row).fill(false);
}

void VirtualMatrix::dropCellsIfHigher(int row)
{
	for (int row = 0; row != m_virtMatrix.size(); row++) {
		for (int col = 0; col != m_virtMatrix.at(row).size(); col++) {
			if (m_virtMatrix.at(row).at(col)) {
				m_virtMatrix.at(row).at(col) = false;
				m_virtMatrix.at(row + 1).at(col) = true;
			}
		}
	}
}

VirtualMatrix::VirtMatrix VirtualMatrix::getMatrix()
{
	return m_virtMatrix;
}

void VirtualMatrix::printMatrix() {
	std::cout << "\n";
	for (int row = 0; row != m_virtMatrix.size(); row++) {
		for (int col = 0; col != m_virtMatrix.at(row).size(); col++) {
			std::cout << m_virtMatrix.at(row).at(col);
		}
		std::cout << "\n";
	}
}

void VirtualMatrix::lowerAllBlocksAboveRow(int rowNumber)
{
	for (int row = rowNumber; row > 0; row--) {
		//std::cout << "Row: " << row << "\n";
		for (int col = 0; col != m_virtMatrix.at(row).size(); col++) {
			if (m_virtMatrix.at(row).at(col)) {
				m_virtMatrix.at(row).at(col) = false;
				m_virtMatrix.at(row + 1).at(col) = true;
			}
		}
	}
}
