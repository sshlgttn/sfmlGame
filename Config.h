#pragma once


class Config
{
	static int height;
	static int width;

public:
	Config();
	static int getHeight();
	static int getWidth();
};

