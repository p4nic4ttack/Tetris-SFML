#ifndef GRIDCELL_H
#define GRIDCELL_H

#include <SFML/Graphics.hpp>
#include "Position.h"
class GridCell
{
private:
	float m_cellSize = 35.f;
	sf::RectangleShape m_square;
	uint8_t m_color{ 0 };
	uint8_t m_fillColor{ 96 };
	Position m_pos;
	

public:
	GridCell(const Position &pos);
	GridCell(const Position &pos, uint8_t, uint8_t, uint8_t);
	GridCell(const Position& pos, uint8_t, uint8_t, uint8_t, float, float);
	GridCell();
	Position& getPosition();
	sf::RectangleShape& getSquare();
	//void replace(const Position &p);
	void setPosition(const Position& pos);
	friend std::ostream& operator<<(std::ostream& out, GridCell cell);
};



#endif // !GRIDCELL_H

