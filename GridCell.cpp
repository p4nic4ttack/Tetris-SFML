#include "GridCell.h"

GridCell::GridCell(const Position& pos) : m_pos(pos), m_square{ sf::Vector2f(m_cellSize , m_cellSize) }
{
	m_square.setOutlineThickness(1.f);
	m_square.setOutlineColor(sf::Color(m_color, m_color, m_color));
	m_square.setFillColor(sf::Color(m_fillColor, m_fillColor, m_fillColor));
	m_square.setPosition((double)m_pos.getX(), (double)m_pos.getY());
}

GridCell::GridCell(const Position& pos, uint8_t r, uint8_t g, uint8_t b) : m_pos(pos), m_square{ sf::Vector2f(m_cellSize, m_cellSize) }
{
	m_square.setFillColor(sf::Color(r, g, b));
	m_square.setOutlineColor(sf::Color(r, g, b));
	m_square.setPosition((double)m_pos.getX(), (double)m_pos.getY());
}

GridCell::GridCell(const Position& pos, uint8_t r, uint8_t g, uint8_t b, float width, float height) : m_pos(pos), m_square{ sf::Vector2f(width, height) }
{
	m_square.setFillColor(sf::Color(r, g, b));
	m_square.setOutlineColor(sf::Color(r, g, b));
	m_square.setPosition((double)m_pos.getX(), (double)m_pos.getY());
}

GridCell::GridCell() : m_square{ sf::Vector2f(m_cellSize, m_cellSize) } {
	m_pos = Position(0, 0);
	m_square.setOutlineThickness(1.f);
	m_square.setOutlineColor(sf::Color(m_color, m_color, m_color));
	m_square.setFillColor(sf::Color(m_fillColor, m_fillColor, m_fillColor));
	m_square.setPosition((double)m_pos.getX(), (double)m_pos.getY());
}

Position &GridCell::getPosition()
{
	return m_pos;
}

sf::RectangleShape& GridCell::getSquare()
{
	return m_square;
}

void GridCell::setPosition(const Position& pos) {
	m_pos = pos;
	m_square.setPosition((double)m_pos.getX(), (double)m_pos.getY());
}

std::ostream& operator<<(std::ostream& out, GridCell cell)
{
	out << "Cell position x: " << cell.getSquare().getPosition().x << " y: " << cell.getSquare().getPosition().y  <<"\n";
	return out;
}
