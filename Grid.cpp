#include "Grid.h"


Grid::Grid()
{
	m_matrix.resize(20);
	int y = 0;
	for (int row = 0; row != m_matrix.size(); row++) {
		int x = 0;
		std::vector<GridCell> temp;
		temp.resize(10);
		for (int col = 0; col != temp.size(); col++) {
			temp.at(col) = GridCell(Position(x, y + 1));
			x += 35;
		}
		m_matrix.at(row) = temp;
		y += 35;
	}
}

Grid::~Grid()
{
	m_matrix.clear();
}

GridCell &Grid::getCell(int row, int col)
{
	return getRow(row).at(col);//getRow(row).at(col);
}


Grid::Storage &Grid::getMatrix()
{
	return m_matrix;
}

std::vector<GridCell>& Grid::getRow(int row)
{
	return m_matrix.at(row);
}
