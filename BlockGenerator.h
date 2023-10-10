#ifndef BLOCKGENERATOR_H
#define BLOCKGENERATOR_H
#include "BlockCollection.h"

class BlockGenerator
{
public:
	BlockGenerator();
	Movable *getRandomBlock();
	int getRandomNumber(int, int);
};

#endif