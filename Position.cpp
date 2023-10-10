#include "Position.h"



Position::Position(int x, int y):m_x(x), m_y(y)
{
	
}

Position::Position()
{
	m_x = 0;
	m_y = 0;
}

int Position::getX() const
{
	return m_x;
}

int Position::getY() const
{
	return m_y;
}

void Position::replace(int x, int y) {
	m_x = x;
	m_y = y;
}