#ifndef GRID_H
#define GRID_H

#include "GridCell.h"
#include <vector>
#include <cstdint>
class Grid
{
private:
	//std::array<std::array<GridCell, 10>, 20> m_matrix;
	typedef std::vector<std::vector<GridCell>> Storage;
	Storage m_matrix;
public:
	Grid();
	~Grid();

	GridCell &getCell(int row, int col);
	Storage &getMatrix();
	std::vector<GridCell> &getRow(int row);
	//std::vector<>
};

#endif
