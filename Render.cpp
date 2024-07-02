#include "Render.h"


enum GameState { MENU, GAME, SETTINGS };
sf::String TileMap[28] = {
	"000000000000000000000000000000000000000000000000000000000000",
	"0                                                          0",
	"0   s                                                      0",
	"0                                                          0",
	"0             s                                            0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                   s                                      0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"0                                                          0",
	"000000000000000000000000000000000000000000000000000000000000",
};




sf::String* Render::getTileMap()
{
	return TileMap;
}

void Render::GenerateMap(sf::RenderWindow& window)
{
	mapImage.loadFromFile("map.png");
	mapTexture.loadFromImage(mapImage);
	mapSprite.setTexture(mapTexture);	
	for (int i = 0; i < 28; i++)
		for (int j = 0; j < 60; j++)
		{
			if (TileMap[i][j] == ' ')  mapSprite.setTextureRect(sf::IntRect(0, 0, 32, 32)); 
			if (TileMap[i][j] == 's')  mapSprite.setTextureRect(sf::IntRect(32, 0, 32, 32));
			if ((TileMap[i][j] == '0')) mapSprite.setTextureRect(sf::IntRect(64, 0, 32, 32));

			
			mapSprite.setPosition(j * 32, i * 32);

			window.draw(mapSprite);
		}
}

Render::Render()
{
	windowSize.x = config.getWidth();
	windowSize.y = config.getHeight();
	window.create(sf::VideoMode(windowSize.x, windowSize.y), "Game", sf::Style::Default);




}

void Render::gameLoop()
{
	Menu menu(window.getSize().x, window.getSize().y);
	Player player;
    Settings settings(window.getSize().x, window.getSize().y);
	GameState state = MENU;
    //Music music("");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (state == MENU) {
                if (event.type == sf::Event::KeyReleased) {
                    if (event.key.code == sf::Keyboard::Up) {
                        menu.moveUp();
                    }
                    else if (event.key.code == sf::Keyboard::Down) {
                        menu.moveDown();
                    }
                    else if (event.key.code == sf::Keyboard::Return) {
                        int selectedItem = menu.getPressedItem();
                        if (selectedItem == 0) {
                            state = GAME;  
                        }
                        else if (selectedItem == 1) {
                            window.close();
                        }
                        else if (selectedItem == 2) {
                            state = SETTINGS;  
                        }
                    }
                }
            }
            else if (state == GAME) {
                if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Escape) {
                        state = MENU;  
                    }
                }
            }
            else if (state == SETTINGS) {
                if (event.type == sf::Event::KeyReleased) {
                    if (event.key.code == sf::Keyboard::Escape) state = MENU;  
                    if (event.key.code == sf::Keyboard::Up) settings.moveUp();
                    if (event.key.code == sf::Keyboard::Down) settings.moveDown();
                    else if (event.key.code == sf::Keyboard::Return) {
                        int selectedItem = settings.getPressedItem();
                        if (selectedItem == 0) {
                            state = GAME;//// SETTINGS
                        }
                        else if (selectedItem == 1) {
                            window.close();
                        }
                    }
                }
            }
        }

        window.clear();

        if (state == MENU) {
            menu.draw(window);
        }
        else if (state == GAME) {
            GenerateMap(window);
            player.Movement(window);
            player.drawPlayer(window);
        }
        else if (state == SETTINGS) {
            settings.draw(window);
        }

        window.display();
    }
}