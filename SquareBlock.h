#ifndef SQUAREBLOCK_H
#define SQUAREBLOCK_H
#include "Movable.h"

class SquareBlock : public Movable
{
private:
	
public:
	SquareBlock(const Position& p, uint8_t r, uint8_t g, uint8_t b);
	void rotate(VirtualMatrix&);
	
};

#endif