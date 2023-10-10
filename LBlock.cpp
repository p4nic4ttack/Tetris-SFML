#include "LBlock.h"

LBlock::LBlock(const Position& p, uint8_t r, uint8_t g, uint8_t b, bool mirrored) : Movable(p, r, g, b), m_mirrored{mirrored}
{
	if (m_mirrored) {
		m_blockArray.at(1) = Block(GridCell(Position(p.getX() + 34, p.getY()), r, g, b, 34.f, 34.f));
		m_blockArray.at(2) = Block(GridCell(Position(p.getX() - 35, p.getY() - 1), r, g, b, 35.f, 35.0f));
		m_blockArray.at(3) = Block(GridCell(Position(p.getX() - 35, p.getY() - 34), r, g, b, 34.f, 34.0f));
	}else{
		m_blockArray.at(1) = Block(GridCell(Position(p.getX() - 34, p.getY()), r, g, b, 34.f, 34.f));
		m_blockArray.at(2) = Block(GridCell(Position(p.getX() + 34, p.getY() - 1), r, g, b, 35.f, 35.0f));
		m_blockArray.at(3) = Block(GridCell(Position(p.getX() + 35, p.getY() - 34), r, g, b, 34.f, 34.0f));
	}
}

void LBlock::rotate(VirtualMatrix &vmatrix)
{
	if(!m_mirrored){
		if (m_amountOfRotations == 0) {
			Position newTop(m_blockArray.at(1).getCell().getPosition().getX() + 34 , m_blockArray.at(1).getCell().getPosition().getY() - 34);
			Position newBottom(m_blockArray.at(2).getCell().getPosition().getX() - 34, m_blockArray.at(2).getCell().getPosition().getY() + 35);
			Position newSideBlock(m_blockArray.at(3).getCell().getPosition().getX() - 1, m_blockArray.at(3).getCell().getPosition().getY() + 69);
			if (canMove(newTop, vmatrix) && canMove(newBottom, vmatrix) && canMove(newSideBlock, vmatrix)) {
				m_blockArray.at(1).getCell().setPosition(newTop);
				m_blockArray.at(2).getCell().setPosition(newBottom);
				m_blockArray.at(3).getCell().setPosition(newSideBlock);
				m_amountOfRotations = 1;
			}
		}
		else if (m_amountOfRotations == 1) {
			Position newRight(m_blockArray.at(1).getCell().getPosition().getX() + 34, m_blockArray.at(1).getCell().getPosition().getY() + 34);
			Position newLeft(m_blockArray.at(2).getCell().getPosition().getX() - 35, m_blockArray.at(2).getCell().getPosition().getY() - 34);
			Position newSideBlock(m_blockArray.at(2).getCell().getPosition().getX() - 35, m_blockArray.at(2).getCell().getPosition().getY());
			if (canMove(newRight, vmatrix) && canMove(newLeft, vmatrix) && canMove(newSideBlock, vmatrix)) {
				m_blockArray.at(1).getCell().setPosition(newRight);
				m_blockArray.at(2).getCell().setPosition(newLeft);
				m_blockArray.at(3).getCell().setPosition(newSideBlock);
				m_amountOfRotations = 2;
			}
		}
		else if (m_amountOfRotations == 2) {
			Position newBottom(m_blockArray.at(1).getCell().getPosition().getX() - 34, m_blockArray.at(1).getCell().getPosition().getY() + 34);
			Position newTop(m_blockArray.at(2).getCell().getPosition().getX() + 34, m_blockArray.at(2).getCell().getPosition().getY() - 35);
			Position newSideBlock(m_blockArray.at(2).getCell().getPosition().getX(), m_blockArray.at(2).getCell().getPosition().getY() - 35);
			if (canMove(newBottom, vmatrix) && canMove(newTop, vmatrix) && canMove(newSideBlock, vmatrix)) {
				m_blockArray.at(1).getCell().setPosition(newBottom);
				m_blockArray.at(2).getCell().setPosition(newTop);
				m_blockArray.at(3).getCell().setPosition(newSideBlock);
				m_amountOfRotations = 3;
			}
		}
		else if (m_amountOfRotations == 3) {
			Position newLeft(m_blockArray.at(1).getCell().getPosition().getX() - 34, m_blockArray.at(1).getCell().getPosition().getY() - 34);
			Position newRight(m_blockArray.at(2).getCell().getPosition().getX() + 35, m_blockArray.at(2).getCell().getPosition().getY() + 34);
			Position newSideBlock(m_blockArray.at(2).getCell().getPosition().getX() + 35, m_blockArray.at(2).getCell().getPosition().getY());
			if (canMove(newLeft, vmatrix) && canMove(newRight, vmatrix) && canMove(newSideBlock, vmatrix)) {
				m_blockArray.at(1).getCell().setPosition(newLeft);
				m_blockArray.at(2).getCell().setPosition(newRight);
				m_blockArray.at(3).getCell().setPosition(newSideBlock);
				m_amountOfRotations = 0;
			}
		}
	}
	else{
		if (m_amountOfRotations == 0) {
			Position newBottom(m_blockArray.at(1).getCell().getPosition().getX() - 34, m_blockArray.at(1).getCell().getPosition().getY() + 34);
			Position newTop(m_blockArray.at(2).getCell().getPosition().getX() + 35, m_blockArray.at(2).getCell().getPosition().getY() - 34);
			Position newSideBlock(m_blockArray.at(3).getCell().getPosition().getX() + 68, m_blockArray.at(3).getCell().getPosition().getY() - 1);
			if (canMove(newBottom, vmatrix) && canMove(newTop, vmatrix) && canMove(newSideBlock, vmatrix)) {
				m_blockArray.at(1).getCell().setPosition(newBottom);
				m_blockArray.at(2).getCell().setPosition(newTop);
				m_blockArray.at(3).getCell().setPosition(newSideBlock);
				m_amountOfRotations = 1;
			}
		}
		else if (m_amountOfRotations == 1) {
			Position newLeft(m_blockArray.at(1).getCell().getPosition().getX() - 34, m_blockArray.at(1).getCell().getPosition().getY() - 34);
			Position newRight(m_blockArray.at(2).getCell().getPosition().getX() + 34, m_blockArray.at(2).getCell().getPosition().getY() + 35);
			Position newSideBlock(m_blockArray.at(3).getCell().getPosition().getX() + 2, m_blockArray.at(3).getCell().getPosition().getY() + 68);
			if (canMove(newLeft, vmatrix) && canMove(newRight, vmatrix) && canMove(newSideBlock, vmatrix)) {
				m_blockArray.at(1).getCell().setPosition(newLeft);
				m_blockArray.at(2).getCell().setPosition(newRight);
				m_blockArray.at(3).getCell().setPosition(newSideBlock);
				m_amountOfRotations = 2;
			}
		}
		else if (m_amountOfRotations == 2) {
			Position newTop(m_blockArray.at(1).getCell().getPosition().getX() + 34, m_blockArray.at(1).getCell().getPosition().getY() - 34);
			Position newBottom(m_blockArray.at(2).getCell().getPosition().getX() - 35, m_blockArray.at(2).getCell().getPosition().getY() + 34);
			Position newSideBlock(m_blockArray.at(3).getCell().getPosition().getX() - 68, m_blockArray.at(3).getCell().getPosition().getY() + 2);
			if(canMove(newTop, vmatrix) && canMove(newBottom, vmatrix) && canMove(newSideBlock, vmatrix)){
				m_blockArray.at(1).getCell().setPosition(newTop);
				m_blockArray.at(2).getCell().setPosition(newBottom);
				m_blockArray.at(3).getCell().setPosition(newSideBlock);
				m_amountOfRotations = 3;
			}
		}
		else if (m_amountOfRotations == 3) {
			Position newRight(m_blockArray.at(1).getCell().getPosition().getX() + 34, m_blockArray.at(1).getCell().getPosition().getY() + 34);
			Position newLeft(m_blockArray.at(2).getCell().getPosition().getX() - 34, m_blockArray.at(2).getCell().getPosition().getY() - 35);
			Position newSideBlock(m_blockArray.at(3).getCell().getPosition().getX() - 2, m_blockArray.at(3).getCell().getPosition().getY() - 69);
			if (canMove(newRight, vmatrix) && canMove(newLeft, vmatrix) && canMove(newSideBlock, vmatrix)) {
				m_blockArray.at(1).getCell().setPosition(newRight);
				m_blockArray.at(2).getCell().setPosition(newLeft);
				m_blockArray.at(3).getCell().setPosition(newSideBlock);
				m_amountOfRotations = 0;
			}
		}
	}
}
