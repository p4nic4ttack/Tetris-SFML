#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdint>
#include "Grid.h"
#include "BlockCollection.h"
#include "BlockGenerator.h"
#include "VirtualMatrix.h"
#include "ScoreView.h"
#include "Menu.h"

class Game
{
private:
	typedef std::vector<Movable*> Storage;
	Grid m_grid;// = Grid();
	sf::RenderWindow m_window;
	sf::Event m_event;
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::Vector2u m_size;
	double m_seconds;
	Storage m_landedBlockStorage;
	VirtualMatrix m_vmatrix;
	ScoreView m_scoreView;
	float m_score;
	bool m_scoreReachedHundred;
	bool m_gameOver;
public:
	Game();
	void startGame();
	void stopGame();
	inline void draw(sf::Sprite &);
	void draw(ScoreView &);
	void draw(Grid &);
	void draw(Movable&);
	void drawLandedBlocks();
	bool checkLanded(Movable&);
	//bool checkGameOver(Movable&);
	void updateVMatrix(Movable*);
	void clearCompletedRows();
	void dropUpperBlocks(int,VirtualMatrix&);
	float calculateScore(const float);
};

#endif
