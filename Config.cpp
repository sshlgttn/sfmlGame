#include "Config.h"

Config::Config()
{

}

int Config::getHeight()
{
	return height;
}

int Config::getWidth()
{
	return width;
}
int Config::height = 900;
int Config::width = 1920;