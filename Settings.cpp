#include "Settings.h"


Settings::Settings(float width, float height) {

    if (!font.loadFromFile("arial.ttf")) {
        return;
    }
    
    settings[0].setFont(font);
    settings[0].setFillColor(sf::Color::Red);
    settings[0].setString("TEST");
    settings[0].setPosition(sf::Vector2f(width / 2, height / (MAX_SIZE_OF_SETTINGS + 1) * 1));

    settings[1].setFont(font);
    settings[1].setFillColor(sf::Color::White);
    settings[1].setString("Exit to menu");
    settings[1].setPosition(sf::Vector2f(width / 2, height / (MAX_SIZE_OF_SETTINGS + 1) * 2));
    
    selectedItemIndex = 0;
}

void Settings::draw(sf::RenderWindow& window)
{
	for(int i = 0; i < MAX_SIZE_OF_SETTINGS; ++i)
	window.draw(settings[i]);
}

void Settings::moveDown()
{
    if (selectedItemIndex + 1 < MAX_SIZE_OF_SETTINGS) {
        settings[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        settings[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void Settings::moveUp()
{
    if (selectedItemIndex - 1 >= 0) {
        settings[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        settings[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

int Settings::getPressedItem() const
{
    return selectedItemIndex;
}