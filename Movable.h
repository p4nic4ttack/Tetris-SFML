#ifndef MOVABLE_H
#define MOVABLE_H
#include <array>
#include <cstdint>
#include "Block.h"
#include "VirtualMatrix.h"

class Movable
{
protected:
	typedef std::array<Block,4> blockList;
	blockList m_blockArray;
	bool m_landed = false;
	Block m_base;

public:
	Movable(const Position& p, uint8_t r, uint8_t g, uint8_t b);
	void drop(VirtualMatrix&);
	void move(int, VirtualMatrix&);
	virtual void rotate(VirtualMatrix&) = 0;
	bool canMove(Position&);
	bool canMove(Position&, VirtualMatrix&);
	bool canMoveRight(Position&);
	bool canMoveLeft(Position&);
	bool canMoveDown(Position&);
	bool isNotAtBottom(VirtualMatrix&);
	blockList getBlockArray();
	bool getIsLanded();
	//bool isAtTop();
	void deleteBlocksAtRow(int);

	//void dropBlocksIfHigherThenRow(int);
	void dropBlocksIfHigher(int, VirtualMatrix&);
};

#endif
