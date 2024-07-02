#include "Player.h"


Player::Player() {
    playerCoord.x = 440;
    playerCoord.y = 400;
    playerSize.x = 64;
    playerSize.y = 64;
    player.setPosition(300, 300);
    player.setSize(playerSize);
    player.setOrigin(playerSize.x/2, playerSize.y/2);

    if (!playerTexture.loadFromFile("pers.png")) {
        std::cerr << "Error loading texture" << std::endl;
    }
    
    player.setTexture(&playerTexture);

    player.setPosition(playerCoord);
}

float Player::getRotationAngle(const sf::Vector2f& from, const sf::Vector2f& to) {
    float dx = to.x - from.x;
    float dy = to.y - from.y;
    return std::atan2(dy, dx) * 180 / 3.14159265;
}

void Player::Movement(sf::RenderWindow& window) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        if (mousePos.x < 32) mousePos.x = 32;
        if (mousePos.x > Config::getWidth() - 32) mousePos.x = 1875;
        if (mousePos.y < 32) mousePos.y = 32;
        if (mousePos.y > Config::getHeight() - 32) mousePos.y = 865;

        if (Render::getTileMap() != nullptr) {
            const sf::String* temp = (Render::getTileMap());
            sf::Vector2f tempCords = window.mapPixelToCoords(mousePos);
            for (int i = 0; i < 28; i++) {
                for (int j = 0; j < 60; j++) {
                    if (j == (int)tempCords.x / 32 && i == (int)tempCords.y / 32 && temp[i][j] == 's') {
                        return;
                    }
                }
            }
        }

        targetPos = window.mapPixelToCoords(mousePos);
    }

    float speed = 0.59f;
    sf::Vector2f direction = targetPos - player.getPosition();
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    playerCoord = targetPos;

    if (length != 0) {
        direction.x /= length;
        direction.y /= length;
    }

    sf::Vector2f offset = direction * speed;
    if (length > speed) {
        sf::Vector2f newPos = player.getPosition() + offset;

        
        if (Render::getTileMap() != nullptr) {
            const sf::String* temp = (Render::getTileMap());
            for (int i = 0; i < 28; i++) {
                for (int j = 0; j < 60; j++) {
                    if (temp[i][j] == 's') {
                        sf::FloatRect stoneRect(j * 32, i * 32, 32, 32);
                        if (stoneRect.contains(newPos)) {
                            return;
                        }
        }
    }
}
        }

        player.move(offset);
    }
    else {
        player.setPosition(targetPos);
    }

    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);

#ifdef DEBUG
    std::cout << "player" << playerCoord.x << " " << playerCoord.y << std::endl;
    std::cout << mousePos.x << " " << mousePos.y << std::endl;
#endif

    float angle = getRotationAngle(player.getPosition(), worldPos);
    player.setRotation(angle - 90);
}


void Player::drawPlayer(sf::RenderWindow& window) {
    window.draw(player);
    window.draw(shape);
}
