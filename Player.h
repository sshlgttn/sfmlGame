#pragma once
#include "SFML/Graphics.hpp"
#include <cmath> 
#include <iostream>
#include "Config.h"
#include "Render.h"

class Player {
    sf::RectangleShape shape;
    sf::RectangleShape player;
    sf::Vector2f playerSize;
    sf::Vector2f playerCoord;
    sf::Vector2f targetPos;
    sf::Texture playerTexture;


    float getRotationAngle(const sf::Vector2f& from, const sf::Vector2f& to);

public:
    Player();
    void Movement(sf::RenderWindow& window);
    void drawPlayer(sf::RenderWindow& window);
};
