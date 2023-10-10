#include "SquareBlock.h"

SquareBlock::SquareBlock(const Position& p, uint8_t r, uint8_t g, uint8_t b) : Movable(p, r, g, b)
{
	m_blockArray.at(1) = Block(GridCell(Position(p.getX() + 34, p.getY()), r, g, b, 34.f, 34.0f));
	m_blockArray.at(2) = Block(GridCell(Position(p.getX(), p.getY() + 34), r, g, b, 34.f, 34.0f));
	m_blockArray.at(3) = Block(GridCell(Position(p.getX() + 34, p.getY() + 34), r, g, b, 34.f, 34.0f));
}


void SquareBlock::rotate(VirtualMatrix&)
{

}

