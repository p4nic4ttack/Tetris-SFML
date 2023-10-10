#ifndef SCOREVIEW_H
#define SCOREVIEW_H
#include "Position.h"
#include <cstdint>
#include <array>
#include <SFML/Graphics.hpp>
#include <string>

class ScoreView
{
private:
	sf::RectangleShape m_rect;
	sf::Font m_scoreFont;
	sf::Text m_scoreText;
	int m_score;
	
public:
	ScoreView(const Position &p);
	sf::RectangleShape &getScoreRectangle();
	sf::Text &getScoreText();
	void setScorePosition(Position p);
	void setScoreText(const int);
	Position getScorePosition();
};


#endif

