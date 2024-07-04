#include "Game.h"

void Game::initWindow()
{
	// Create window
	window = new sf::RenderWindow(sf::VideoMode(800, 600), "SFML works!");
}

Game::Game()
{
	initWindow();
}

Game::~Game()
{
	delete window;
}

void Game::updateSFMLEvents()
{
	while (window->pollEvent(sfEvent))
	{
		if (sfEvent.type == sf::Event::Closed)
			window->close();
	}
}

void Game::update()
{
	updateSFMLEvents();
}

void Game::render()
{
	window->clear();

	// Render items here

	window->display();
}

void Game::run()
{
	while (window->isOpen())
	{
		update();
		render();
	}
}
