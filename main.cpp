#include <iostream>

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Grid.h"
#include "SquareBlock.h"


int main()
{
	srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
	rand();
	Game game;
	game.startGame();
	return EXIT_SUCCESS;
}
