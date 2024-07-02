#pragma once
#include "SFML/Graphics.hpp"
class Settings
{  
    const static int MAX_SIZE_OF_SETTINGS = 2;
    int selectedItemIndex;
    sf::Font font;
    sf::Text settings[2];
public: 
    void draw(sf::RenderWindow& window);
    void moveDown();
    void moveUp();
    int getPressedItem() const;
    Settings(float width, float height);
};

