#pragma once
#include "SFML/Audio.hpp"

class Music
{
	sf::SoundBuffer backgroundBuffer;
	sf::Sound backgroundSound;
public:
	Music(sf::String&adr);
	void playBackroundMusic();
};

