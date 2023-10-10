#ifndef TRIANGLEBLOCK
#define TRIANGLEBLOCK
#include "Movable.h"

class TriangleBlock: public Movable
{
private:
	int m_amountOfRotations = 0;
public:
	TriangleBlock(const Position&, uint8_t, uint8_t, uint8_t);
	void rotate(VirtualMatrix &);
	
};

#endif