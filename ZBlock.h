#ifndef ZBLOCK_H
#define ZBLOCK_H
#include "Movable.h"

class ZBlock: public Movable
{
private:
	int m_amountOfRotations = 0;
	bool m_isMirrored;
public:
	ZBlock(const Position& p, uint8_t r, uint8_t g, uint8_t b, bool mirrored = false);
	void rotate(VirtualMatrix&);
};

#endif