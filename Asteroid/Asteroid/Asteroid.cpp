#pragma once
#include "Asteroid.h"
#include <iostream>

using std::cout;
using std::endl;

Asteroid::Asteroid()
{
	sf::Texture t;
	if (!t.loadFromFile("asteroid-texture.png"))
	{
		cout << "Texture not loaded." << endl;
	}
	else
	{
		cout << "Texture loaded." << endl;
	}
	mBody.setTexture(t);
	mBody.setPosition(25, 30);
	//mBody.setScale(.1, .1);
}

Asteroid::Asteroid(sf::Texture & texture)
{
	mBody.setTexture(texture);
}

sf::Sprite & Asteroid::getBody()
{
	return mBody;
}