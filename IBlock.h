#ifndef IBLOCK_H
#define IBLOCK_H
#include "Position.h"
#include "VirtualMatrix.h"
class IBlock
{
public:
	virtual void drop(VirtualMatrix&) = 0;
	virtual void move(int, VirtualMatrix&) = 0;
	virtual void rotate(VirtualMatrix&) = 0;
	virtual bool canMove(Position&) = 0;
	virtual bool canMove(Position&, VirtualMatrix&) = 0;
	virtual bool canMoveRight(Position&) = 0;
	virtual bool canMoveLeft(Position&) = 0;
	virtual bool isNotAtBottom(VirtualMatrix&) = 0;
};

#endif // !IBLOCK_H



