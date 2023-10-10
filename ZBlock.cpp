#include "ZBlock.h"
#include <iostream>
ZBlock::ZBlock(const Position& p, uint8_t r, uint8_t g, uint8_t b, bool isMirrored): Movable(p, r, g, b), m_isMirrored{isMirrored}
{
	if (!m_isMirrored) {
		m_blockArray.at(1) = Block(GridCell(Position(p.getX(), p.getY() - 34), r, g, b, 34.f, 34.f)); // Top middle
		m_blockArray.at(2) = Block(GridCell(Position(p.getX() + 34, p.getY()), r, g, b, 34.f, 34.0f)); // Right bottom
		m_blockArray.at(3) = Block(GridCell(Position(p.getX() - 34, p.getY() - 34), r, g, b, 34.f, 34.0f)); // Top left
	}
	else {
		m_blockArray.at(1) = Block(GridCell(Position(p.getX(), p.getY() + 34), r, g, b, 34.f, 34.f)); // Bottom middle
		m_blockArray.at(2) = Block(GridCell(Position(p.getX() - 34, p.getY() + 34), r, g, b, 34.f, 34.0f)); // Bottom left
		m_blockArray.at(3) = Block(GridCell(Position(p.getX() + 34, p.getY()), r, g, b, 34.f, 34.0f)); // Top Right
	}
}

void ZBlock::rotate(VirtualMatrix &vmatrix)
{
	if (!m_isMirrored) {
		if (m_amountOfRotations == 0) {
			Position newRightMiddle(m_blockArray.at(1).getCell().getPosition().getX() + 34, m_blockArray.at(1).getCell().getPosition().getY() + 34);
			Position newBottom(m_blockArray.at(2).getCell().getPosition().getX() - 34, m_blockArray.at(2).getCell().getPosition().getY() + 34);
			Position newTop(m_blockArray.at(3).getCell().getPosition().getX() + 68, m_blockArray.at(3).getCell().getPosition().getY());
			if (canMove(newRightMiddle, vmatrix) && canMove(newBottom, vmatrix) && canMove(newTop, vmatrix)) {
				m_blockArray.at(1).getCell().setPosition(newRightMiddle);
				m_blockArray.at(2).getCell().setPosition(newBottom);
				m_blockArray.at(3).getCell().setPosition(newTop);
				m_amountOfRotations = 1;
			}
		}
		else if (m_amountOfRotations == 1) {
			Position newBottomMiddle(m_blockArray.at(1).getCell().getPosition().getX() - 34, m_blockArray.at(1).getCell().getPosition().getY() + 34);
			Position newTopLeft(m_blockArray.at(2).getCell().getPosition().getX() - 34, m_blockArray.at(2).getCell().getPosition().getY() - 34);
			Position newRight(m_blockArray.at(3).getCell().getPosition().getX(), m_blockArray.at(3).getCell().getPosition().getY() + 68);
			if (canMove(newBottomMiddle, vmatrix) && canMove(newTopLeft, vmatrix) && canMove(newRight, vmatrix)) {
				m_blockArray.at(1).getCell().setPosition(newBottomMiddle);
				m_blockArray.at(2).getCell().setPosition(newTopLeft);
				m_blockArray.at(3).getCell().setPosition(newRight);
				m_amountOfRotations = 2;
			}

		}
		else if (m_amountOfRotations == 2) {
			Position newMiddleLeft(m_blockArray.at(1).getCell().getPosition().getX() - 34, m_blockArray.at(1).getCell().getPosition().getY() - 34);
			Position newTop(m_blockArray.at(2).getCell().getPosition().getX() + 34, m_blockArray.at(2).getCell().getPosition().getY() - 34);
			Position newBottom(m_blockArray.at(3).getCell().getPosition().getX() - 68, m_blockArray.at(3).getCell().getPosition().getY());
			if (canMove(newBottom, vmatrix) && canMove(newTop, vmatrix) && canMove(newBottom, vmatrix)) {
				m_blockArray.at(1).getCell().setPosition(newMiddleLeft);
				m_blockArray.at(2).getCell().setPosition(newTop);
				m_blockArray.at(3).getCell().setPosition(newBottom);
				m_amountOfRotations = 3;
			}
		}
		else if (m_amountOfRotations == 3) {
			Position newTopMiddle(m_blockArray.at(1).getCell().getPosition().getX() + 34, m_blockArray.at(1).getCell().getPosition().getY() - 34);
			Position newRight(m_blockArray.at(2).getCell().getPosition().getX() + 34, m_blockArray.at(2).getCell().getPosition().getY() + 34);
			Position newTopLeft(m_blockArray.at(3).getCell().getPosition().getX(), m_blockArray.at(3).getCell().getPosition().getY() - 68);
			if (canMove(newTopMiddle, vmatrix) && canMove(newRight, vmatrix) && canMove(newTopLeft, vmatrix)) {
				m_blockArray.at(1).getCell().setPosition(newTopMiddle);
				m_blockArray.at(2).getCell().setPosition(newRight);
				m_blockArray.at(3).getCell().setPosition(newTopLeft);
				m_amountOfRotations = 0;
			}
		}
	}
	else {
		if (m_amountOfRotations == 0) {
			Position newLeftMiddle(m_blockArray.at(1).getCell().getPosition().getX() - 34, m_blockArray.at(1).getCell().getPosition().getY() - 34);
			Position newTop(m_blockArray.at(2).getCell().getPosition().getX(), m_blockArray.at(2).getCell().getPosition().getY() - 68);
			Position newBottom(m_blockArray.at(3).getCell().getPosition().getX() - 34, m_blockArray.at(3).getCell().getPosition().getY() + 34);
			if (canMove(newLeftMiddle, vmatrix) && canMove(newTop, vmatrix) && canMove(newBottom, vmatrix)) {
				m_blockArray.at(1).getCell().setPosition(newLeftMiddle);
				m_blockArray.at(2).getCell().setPosition(newTop);
				m_blockArray.at(3).getCell().setPosition(newBottom);
				m_amountOfRotations = 1;
			}
		}
		else if (m_amountOfRotations == 1) {
			Position newTopMiddle(m_blockArray.at(1).getCell().getPosition().getX() + 34, m_blockArray.at(1).getCell().getPosition().getY() - 34);
			Position newRight(m_blockArray.at(2).getCell().getPosition().getX() + 68, m_blockArray.at(2).getCell().getPosition().getY());
			Position newLeft(m_blockArray.at(3).getCell().getPosition().getX() - 34, m_blockArray.at(3).getCell().getPosition().getY() - 34);
			if (canMove(newTopMiddle, vmatrix) && canMove(newRight, vmatrix) && canMove(newLeft, vmatrix)) {
				m_blockArray.at(1).getCell().setPosition(newTopMiddle);
				m_blockArray.at(2).getCell().setPosition(newRight);
				m_blockArray.at(3).getCell().setPosition(newLeft);
				m_amountOfRotations = 2;
			}
		}
		else if (m_amountOfRotations == 2) {
			Position newRightMiddle(m_blockArray.at(1).getCell().getPosition().getX() + 34, m_blockArray.at(1).getCell().getPosition().getY() + 34);
			Position newBottom(m_blockArray.at(2).getCell().getPosition().getX(), m_blockArray.at(2).getCell().getPosition().getY() + 68);
			Position newTop(m_blockArray.at(3).getCell().getPosition().getX() + 34, m_blockArray.at(3).getCell().getPosition().getY() - 34);
			if (canMove(newRightMiddle) && canMove(newBottom) && canMove(newTop)) {
				m_blockArray.at(1).getCell().setPosition(newRightMiddle);
				m_blockArray.at(2).getCell().setPosition(newBottom);
				m_blockArray.at(3).getCell().setPosition(newTop);
				m_amountOfRotations = 3;
			}
		}
		else if (m_amountOfRotations == 3) {
			Position newBottomMiddle(m_blockArray.at(1).getCell().getPosition().getX() - 34, m_blockArray.at(1).getCell().getPosition().getY() + 34);
			Position newBottomLeft(m_blockArray.at(2).getCell().getPosition().getX() - 68, m_blockArray.at(2).getCell().getPosition().getY());
			Position newTop(m_blockArray.at(3).getCell().getPosition().getX() + 34, m_blockArray.at(3).getCell().getPosition().getY() + 34);
			if (canMove(newBottomMiddle, vmatrix) && canMove(newBottomLeft, vmatrix) && canMove(newTop, vmatrix)) {
				m_blockArray.at(1).getCell().setPosition(newBottomMiddle);
				m_blockArray.at(2).getCell().setPosition(newBottomLeft);
				m_blockArray.at(3).getCell().setPosition(newTop);
				m_amountOfRotations = 0;
			}
		}
	}
		
}
