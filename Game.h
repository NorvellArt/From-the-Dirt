#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Game
{
private:
	// Variables
	sf::RenderWindow *window;
	sf::Event sfEvent;

	// Init functions
	void initWindow();

public:
	// Constructors/Destructors
	Game();
	virtual ~Game();
	
	// Functions
	void updateSFMLEvents();
	void update();
	void render();
	void run();
};

