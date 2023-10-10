#include <cstdlib>
#include <ctime>
#include "BlockGenerator.h"



BlockGenerator::BlockGenerator()
{	
}


Movable *BlockGenerator::getRandomBlock()
{
	int random{ getRandomNumber(0,6) };
	switch (random) {
		case 0:
		{
			return new LBlock(Position(175, 36), 255, 102, 0);
		}
		case 1:
		{
			return new LBlock(Position(140, 36), 0, 92, 230, true);
		}
		case 2:
		{
			return new ZBlock(Position(175, 36), 60, 79, 255);
		}
		case 3:
		{
			return new ZBlock(Position(140, 1), 102, 255, 51, true);
		}
		case 4: 
		{
			return new LineBlock(Position(105, 1), 102, 204, 255);
		}
		case 5:
		{
			return new TriangleBlock(Position(140, 36), 153, 51, 255);
		}
		case 6:
		{
			return new SquareBlock(Position(140, 1), 255, 255, 51);
		}
	}
}


int BlockGenerator::getRandomNumber(int min, int max) {
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
