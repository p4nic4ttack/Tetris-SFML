#ifndef LBLOCK_H
#define LBLOCK_H
#include "Movable.h"

class LBlock : public Movable
{
private:
	int m_amountOfRotations = 0;
	bool m_mirrored;
public:
	LBlock(const Position& p, uint8_t r, uint8_t g, uint8_t b, bool mirrored = false);
	void rotate(VirtualMatrix &);
	
};

#endif