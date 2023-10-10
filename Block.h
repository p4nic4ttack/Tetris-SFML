#ifndef BLOCK_H
#define BLOCK_H
#include <cstdint>
#include "GridCell.h"
#include "IBlock.h"

class Block : public IBlock
{
private:
	bool m_landed = false;
	GridCell m_cell;

public:
	Block(GridCell cell) :m_cell(cell) {};
	Block();
	GridCell &getCell();
	void move(int x, VirtualMatrix&);
	// Drop does an additional check to know if the block already is located at the bottom, if not drops
	void drop(VirtualMatrix&);
	//Lower drops the block unconditionally
	void lower();
	void rotate(VirtualMatrix&);
	void deleteBlock();
	bool canMove(Position&);
	bool canMove(Position &, VirtualMatrix&);
	bool canMoveRight(Position &);
	bool canMoveLeft(Position &);
	bool canMoveBottom(Position &);
	bool isNotAtBottom(VirtualMatrix&);
	//bool isAtTop(VirtualMatrix&);
};


#endif // !BLOCK_H


