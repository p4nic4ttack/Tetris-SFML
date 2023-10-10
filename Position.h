#ifndef POSITION_H
#define POSITION_H
#include <stdint.h>
class Position
{
private:
	int m_x;
	int m_y;
public:
	Position(int, int);
	Position();
	int getX()const;
	int getY()const;
	void replace(int,int);
};


#endif // !POSITION_H


