#pragma once
#include <SFML/Graphics.hpp>

class Menu {
public:
    Menu(float width, float height);
    ~Menu();

    void draw(sf::RenderWindow& window);
    void moveUp();
    void moveDown();
    int getPressedItem() const;

private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[3];

    static const int MAX_NUMBER_OF_ITEMS = 3;
};
