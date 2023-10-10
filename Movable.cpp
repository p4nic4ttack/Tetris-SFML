#include <iostream>
#include "Movable.h"


Movable::Movable(const Position& p, uint8_t r, uint8_t g, uint8_t b) : m_base(GridCell(p, r, g, b, 34.f, 34.0f))
{
	m_blockArray.at(0) = m_base;
}

void Movable::move(int x, VirtualMatrix &vmatrix)
{
	std::array<Position, 4> positions;
	int i = 0;
	for (auto& block : m_blockArray) {
		positions.at(i) = Position(block.getCell().getPosition().getX() + x, block.getCell().getPosition().getY());
		i++;
	}
	if (canMove(positions.at(0), vmatrix) && canMove(positions.at(1), vmatrix) && canMove(positions.at(2), vmatrix) && canMove(positions.at(3), vmatrix)) {
		for (auto& block : m_blockArray) {
			block.move(x, vmatrix);
		}
	}
}

void Movable::drop(VirtualMatrix &vmatrix)
{
	if (isNotAtBottom(vmatrix)) {
		for (auto& block : m_blockArray) {
			block.drop(vmatrix);
		}
	}
}

bool Movable::canMove(Position& newPos)
{
	return !m_landed && canMoveLeft(newPos) && canMoveRight(newPos) && canMoveDown(newPos);
}

bool Movable::canMove(Position &newPos, VirtualMatrix &vmatrix)
{
	return !m_landed && canMoveLeft(newPos) && canMoveRight(newPos) && canMoveDown(newPos) && !vmatrix.checkOccupied(newPos);
}

bool Movable::canMoveRight(Position &p)
{
	for (auto& block : m_blockArray) {
		if (!block.canMoveRight(p)) {
			return false;
		}
	}
	return true;
}

bool Movable::canMoveLeft(Position &p)
{
	for (auto& block : m_blockArray) {
		if (!block.canMoveLeft(p)) {
			return false;
		}
	}
	return true;
}

bool Movable::canMoveDown(Position &p)
{
	return p.getY() < 660;
}

bool Movable::isNotAtBottom(VirtualMatrix &vmatrix)
{
	for (auto& block : m_blockArray) {
		if (!block.isNotAtBottom(vmatrix)) {
			m_landed = true;
			return false;
		}
	}
	return true;
}

Movable::blockList Movable::getBlockArray()
{
	return m_blockArray;
}

bool Movable::getIsLanded()
{
	return m_landed;
}

void Movable::deleteBlocksAtRow(int row)
{
	int rowHeight = row * 35;
	for (int row = 0; row != m_blockArray.size(); row++) {
		int YPos = m_blockArray.at(row).getCell().getPosition().getY();
		if (rowHeight - 15 < YPos && rowHeight + 15 > YPos) {
			m_blockArray.at(row).deleteBlock();
		}
	}
}

void Movable::dropBlocksIfHigher(int row, VirtualMatrix &vmatrix)
{
	for (auto &block : m_blockArray) {
		if (block.getCell().getPosition().getY() < ((row * 35) - 15)) {
			//std::cout << "Drop block\n";
			block.lower();
		}
	}
}
