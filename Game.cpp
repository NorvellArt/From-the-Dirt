#include "Game.h"

void Game::initWindow()
{
	std::ifstream ifs("Config/window.ini");

	std::string title = "Title";
	sf::VideoMode window_bounds(800, 600);
	unsigned framerate_limit = 120;
	bool vertical_sync_enabled = false;

	if (ifs.is_open())
	{
		std::getline(ifs, title);
		ifs >> window_bounds.width >> window_bounds.height;
		ifs >> framerate_limit;
		ifs >> vertical_sync_enabled;
	}

	ifs.close();

	window = new sf::RenderWindow(window_bounds, title);
	window->setFramerateLimit(framerate_limit);
	window->setVerticalSyncEnabled(vertical_sync_enabled);
}

Game::Game()
{
	initWindow();
}

Game::~Game()
{
	delete window;
}

void Game::updateDt()
{
	// Udate dt every frame render
	dt = clock.restart().asSeconds();

	// Checks dt time for performance
	// std::cout << dt << std::endl;
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
		updateDt();
		update();
		render();
	}
}
