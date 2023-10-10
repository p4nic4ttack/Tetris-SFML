#include "TriangleBlock.h"

TriangleBlock::TriangleBlock(const Position& p, uint8_t r, uint8_t g, uint8_t b) :Movable(p, r, g, b)
{
	m_blockArray.at(1) = Block(GridCell(Position(p.getX() - 34, p.getY()), r, g, b, 34.f, 34.f));
	m_blockArray.at(2) = Block(GridCell(Position(p.getX(), p.getY() - 34), r, g, b, 34.f, 34.0f));
	m_blockArray.at(3) = Block(GridCell(Position(p.getX() + 34, p.getY()), r, g, b, 34.f, 34.0f));
}


void TriangleBlock::rotate(VirtualMatrix &vmatrix)
{
	if (m_amountOfRotations == 0) {
		Position newTop(m_blockArray.at(1).getCell().getPosition().getX() + 34, m_blockArray.at(1).getCell().getPosition().getY() - 34);
		Position newRight(m_blockArray.at(2).getCell().getPosition().getX() + 34, m_blockArray.at(2).getCell().getPosition().getY() + 34);
		Position newBottom(m_blockArray.at(3).getCell().getPosition().getX() - 34, m_blockArray.at(3).getCell().getPosition().getY() + 34);
		if (canMove(newTop, vmatrix) && canMove(newRight, vmatrix) && canMove(newBottom, vmatrix)) {
			m_blockArray.at(1).getCell().setPosition(newTop);
			m_blockArray.at(2).getCell().setPosition(newRight);
			m_blockArray.at(3).getCell().setPosition(newBottom);
			m_amountOfRotations = 1;
		}
		
	}
	else if (m_amountOfRotations == 1) {
		Position newRight(m_blockArray.at(1).getCell().getPosition().getX() + 34, m_blockArray.at(1).getCell().getPosition().getY() + 34);
		Position newBottom(m_blockArray.at(2).getCell().getPosition().getX() - 34, m_blockArray.at(2).getCell().getPosition().getY() + 34);
		Position newLeft(m_blockArray.at(3).getCell().getPosition().getX() - 34, m_blockArray.at(3).getCell().getPosition().getY() - 34);
		if (canMove(newRight, vmatrix) && canMove(newBottom, vmatrix) && canMove(newLeft, vmatrix)) {
			m_blockArray.at(1).getCell().setPosition(newRight);
			m_blockArray.at(2).getCell().setPosition(newBottom);
			m_blockArray.at(3).getCell().setPosition(newLeft);
			m_amountOfRotations = 2;
		}
	}
	else if (m_amountOfRotations == 2) {
		Position newBottom(m_blockArray.at(1).getCell().getPosition().getX() - 34, m_blockArray.at(1).getCell().getPosition().getY() + 34);
		Position newLeft(m_blockArray.at(2).getCell().getPosition().getX() - 34, m_blockArray.at(2).getCell().getPosition().getY() - 34);
		Position newTop(m_blockArray.at(3).getCell().getPosition().getX() + 34, m_blockArray.at(3).getCell().getPosition().getY() - 34);
		if (canMove(newBottom, vmatrix) && canMove(newLeft, vmatrix) && canMove(newTop, vmatrix)) {
			m_blockArray.at(1).getCell().setPosition(newBottom);
			m_blockArray.at(2).getCell().setPosition(newLeft);
			m_blockArray.at(3).getCell().setPosition(newTop);
			m_amountOfRotations = 3;
		}
	}
	else if (m_amountOfRotations == 3) {
		Position newLeft(m_blockArray.at(1).getCell().getPosition().getX() - 34, m_blockArray.at(1).getCell().getPosition().getY() - 34);
		Position newTop(m_blockArray.at(2).getCell().getPosition().getX() + 34, m_blockArray.at(2).getCell().getPosition().getY() - 34);
		Position newRight(m_blockArray.at(3).getCell().getPosition().getX() + 34, m_blockArray.at(3).getCell().getPosition().getY() + 34);
		if (canMove(newLeft, vmatrix) && canMove(newTop, vmatrix) && canMove(newRight, vmatrix)) {
			m_blockArray.at(1).getCell().setPosition(newLeft);
			m_blockArray.at(2).getCell().setPosition(newTop);
			m_blockArray.at(3).getCell().setPosition(newRight);
			m_amountOfRotations = 0;
		}
	}
}
