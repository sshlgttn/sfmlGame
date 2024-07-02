#pragma once
#include "SFML/Graphics.hpp"
#include "Config.h"
#include "Player.h"
#include "Menu.h"
#include "Settings.h"
#include "Music.h"

class Render
{
	enum GameState { MENU, GAME, SETTINGS };

	sf::RenderWindow window;
	sf::Vector2u windowSize;
	Config config;
	sf::Image mapImage;
	sf::Texture mapTexture;
	sf::Sprite mapSprite;
	void GenerateMap(sf::RenderWindow& window);

public:
	static sf::String* getTileMap();
	Render();
	void gameLoop();
};

