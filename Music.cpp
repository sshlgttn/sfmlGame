#include "Music.h"

Music::Music(sf::String& adr)
{
	if (!backgroundBuffer.loadFromFile(adr)) return;
	backgroundSound.setBuffer(backgroundBuffer);

}

void Music::playBackroundMusic()
{
	backgroundSound.play();
}
