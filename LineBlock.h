#ifndef LINEBLOCK_H
#define LINEBLOCK_H
#include "Movable.h"

class LineBlock: public Movable
{
private:
	int m_amountOfRotations = 0;
public:
	LineBlock(const Position& p, uint8_t r, uint8_t g, uint8_t b);
	void rotate(VirtualMatrix &);
};



#endif // !LINEBLOCK_H
