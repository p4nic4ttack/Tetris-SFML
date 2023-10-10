 #include "Game.h"

Game::Game() : m_window{ sf::VideoMode(576, 700), "Tetris" }, m_scoreView{Position(390,595)}
{
	m_grid = Grid();
	m_texture.loadFromFile("arcade.png");
	m_size = m_texture.getSize();
	m_sprite.setTexture(m_texture);
	m_sprite.move(-450, 0);
	m_seconds = 1;
	m_score = 0;
	m_scoreReachedHundred = false;
	m_gameOver = false;
}

void Game::startGame()
{
	BlockGenerator blockgen;
	auto block = blockgen.getRandomBlock();
	std::clock_t start;
	double duration;
	start = std::clock();

	
	while (m_window.isOpen() && !m_gameOver)
	{
		while (m_window.pollEvent(m_event))
		{
			if (m_event.type == sf::Event::Closed)
				m_window.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
			{
				block->move(-35, m_vmatrix);
				std::cout << "Live Keyboard Input: Left Key" << std::endl;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
			{
				block->move(35, m_vmatrix);
				std::cout << "Live Keyboard Input: Right Key" << std::endl;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
			{
				block->rotate(m_vmatrix);
				std::cout << "Live Keyboard Input: Up Key" << std::endl;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
			{
				block->drop(m_vmatrix);
				std::cout << "Live Keyboard Input: Down Key" << std::endl;
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{
				std::cout << "Live Mouse Input: Left Button" << std::endl;
			}
		}

		// update the game
		m_window.clear();
		//BACKGROUND
		m_window.draw(m_sprite);

		
		draw(m_grid);
		draw(*block);
		draw(m_scoreView);
		drawLandedBlocks();

		m_window.display();
		
		
		
		duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
		if (duration > m_seconds) {
			m_seconds += 1;
			block->drop(m_vmatrix);
		}
		if (block->getIsLanded()) {
			m_landedBlockStorage.push_back(block);
			updateVMatrix(block);
			if(m_gameOver){
				//m_texture.loadFromFile("/tmp/this-is-so-much-worse-than-the-game-over-screen.jpeg");
				//m_size = m_texture.getSize();
				//m_sprite.setTexture(m_texture);
				 //sf::Window window(sf::VideoMode(800, 600), "My window");
				stopGame();	 
				 
				
			}
			block = blockgen.getRandomBlock();
			clearCompletedRows();
			//checkGameOver(block);
			m_scoreView.setScoreText(int(m_score));
			std::cout << "Row 19 completed: " << m_vmatrix.checkRowComplete(19) << "\n";
		}
			
	}
	
}

inline void Game::draw(sf::Sprite &sprite)
{
	m_window.draw(sprite);
}

void Game::stopGame(){
	m_grid.~Grid();
	m_landedBlockStorage.clear();
	Menu menu(m_window.getSize().x, m_window.getSize().y);
	while(m_window.isOpen()){
		while (m_window.pollEvent(m_event))
		{
			switch (m_event.type)
			{
			case sf::Event::KeyReleased:
				switch (m_event.key.code)
				{
				case sf::Keyboard::Up:
					menu.MoveUp();
					break;

				case sf::Keyboard::Down:
					menu.MoveDown();
					break;

				case sf::Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
						std::cout << "Play button has been pressed" << std::endl;
						break;
					case 1:
						std::cout << "Option button has been pressed" << std::endl;
						break;
					case 2:
						m_window.close();
						break;
					}

					break;
				}

				break;
			case sf::Event::Closed:
				m_window.close();

				break;

			}
		}
		m_window.clear();
		menu.draw(m_window);
		m_window.display();
	}
}

void Game::draw(ScoreView &scoreView)
{
	if (!m_scoreReachedHundred && m_score > 99) {
		m_scoreReachedHundred = true;
		scoreView.setScorePosition(Position(scoreView.getScorePosition().getX()-17, scoreView.getScorePosition().getY()));
	}
	m_window.draw(scoreView.getScoreRectangle());
	m_window.draw(scoreView.getScoreText());
}

void Game::draw(Grid &grid)
{
	for (int row = 0; row != grid.getMatrix().size(); row++) {
		for (int col = 0; col != grid.getMatrix().at(row).size(); col++) {
			m_window.draw(grid.getCell(row, col).getSquare());
		}
	}
}

void Game::draw(Movable& m)
{
	for (auto& b : m.getBlockArray()) {
		m_window.draw(b.getCell().getSquare());
	}
}

void Game::drawLandedBlocks()
{
	if (!m_landedBlockStorage.empty()) {
		for (auto& ptr : m_landedBlockStorage) {
			draw(*ptr);
		}
	}
}

bool Game::checkLanded(Movable &block)
{
	return block.getIsLanded();
}

void Game::updateVMatrix(Movable *movable)
{
	for (auto &block : movable->getBlockArray()) {
		m_gameOver = !m_vmatrix.setBlock(block.getCell().getPosition());
	}
	m_vmatrix.printMatrix();
}




void Game::clearCompletedRows()
{
	float amountRows = 0;
	for (int i = 0; i != m_vmatrix.getMatrix().size(); i++) {
		if (m_vmatrix.checkRowComplete(i)) {
			amountRows += 1;
			m_vmatrix.clearCompletedRow(i);
			for (auto &movable : m_landedBlockStorage) {
				movable->deleteBlocksAtRow(i);
			}
			m_vmatrix.lowerAllBlocksAboveRow(i);
			dropUpperBlocks(i, m_vmatrix);
			drawLandedBlocks();
			m_vmatrix.printMatrix();
		}

	}
	m_score += calculateScore(amountRows);
	std::cout << m_score;
}

void Game::dropUpperBlocks(int row, VirtualMatrix &vmatrix)
{
	for (auto& blockCompositions : m_landedBlockStorage) {
		blockCompositions->dropBlocksIfHigher(row, vmatrix);
	}
}

float Game::calculateScore(const float rows)
{
	if (rows == 1)
		return 20;
	else
		return (20 * rows) + ((20*rows)/100)*20;
}
