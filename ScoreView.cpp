#include "ScoreView.h"

ScoreView::ScoreView(const Position &p) : m_rect{sf::Vector2f(135,52)}
{
	m_rect.setPosition(p.getX(),p.getY());
	m_rect.setOutlineColor(sf::Color(252, 232, 3));
	m_rect.setFillColor(sf::Color(62, 64, 60));
	m_rect.setOutlineThickness(6);
	m_score = 0;
	m_scoreFont.loadFromFile("ARCADE_I.TTF");
	m_scoreText.setFont(m_scoreFont);
	m_scoreText.setCharacterSize(24);
	m_scoreText.setFillColor(sf::Color().White);
	m_scoreText.setPosition(p.getX() + 50, p.getY() + 12.5);
	setScoreText(0);
}

sf::RectangleShape &ScoreView::getScoreRectangle()
{
	return m_rect;
}

sf::Text &ScoreView::getScoreText()
{
	return m_scoreText;
}

void ScoreView::setScorePosition(Position p)
{
	m_scoreText.setPosition(p.getX(),p.getY());
}


void ScoreView::setScoreText(const int score)
{
	m_scoreText.setString(std::to_string(score));
}

Position ScoreView::getScorePosition()
{
	return Position(m_scoreText.getPosition().x, m_scoreText.getPosition().y);
}
