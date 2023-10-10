#include "Block.h"
#include <iostream>

Block::Block()
{
	m_cell = GridCell(Position(0,0), 0, 0, 0);
}

GridCell& Block::getCell()
{
	return m_cell;
}

void Block::move(int x, VirtualMatrix &vmatrix)
{
	int cur_x = m_cell.getPosition().getX();
	int cur_y = m_cell.getPosition().getY();
	Position newPos(cur_x + x, cur_y);
	if (canMove(newPos, vmatrix)) {
		
		m_cell.setPosition(newPos);
	}
}

void Block::drop(VirtualMatrix &vmatrix)
{
	//std::cout << "\nNot at bottom: " << isNotAtBottom();
	if(isNotAtBottom(vmatrix)){
		int cur_x = m_cell.getPosition().getX();
		int cur_y = m_cell.getPosition().getY();
		m_cell.setPosition(Position(cur_x, cur_y + 35));
	}
}

void Block::lower()
{
	int cur_x = m_cell.getPosition().getX();
	int cur_y = m_cell.getPosition().getY();
	m_cell.setPosition(Position(cur_x, cur_y + 35));
}

void Block::rotate(VirtualMatrix &)
{

}

void Block::deleteBlock()
{
	m_cell.getSquare().setOutlineColor(sf::Color::Transparent);
	m_cell.getSquare().setFillColor(sf::Color::Transparent);
}

bool Block::canMove(Position& newPos)
{
	return !m_landed && canMoveLeft(newPos) && canMoveRight(newPos) && canMoveBottom(newPos);
}

bool Block::canMove(Position& newPos, VirtualMatrix& vmatrix)
{
	return !m_landed && canMoveLeft(newPos) && canMoveRight(newPos) && canMoveBottom(newPos) && !vmatrix.checkOccupied(newPos);
}

bool Block::canMoveRight(Position &p) {
	return p.getX() <= 315;
}

bool Block::canMoveLeft(Position &p) {
	return p.getX() >= 0;
}


bool Block::isNotAtBottom(VirtualMatrix &vmatrix)
{
	Position newPos = m_cell.getPosition();
	newPos.replace(newPos.getX(), newPos.getY() + 35);
	if (m_cell.getPosition().getY() < 660 && !vmatrix.checkOccupied(newPos)) {
		return true;
	}
	m_landed = true;
	return false;
}

/*bool Block::isAtTop(VirtualMatrix &vmatrix)
{
	Position newPos = m_cell.getPosition();
	newPos.replace(newPos.getX(), newPos.getY() + 35);
	if (m_cell.getPosition().getY() < 700) {
		return true;
	}
	return false;
}*/

bool Block::canMoveBottom(Position &pos)
{
	return pos.getY() < 660;
}
