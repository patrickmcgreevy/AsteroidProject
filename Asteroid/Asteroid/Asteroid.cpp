#pragma once
#include "Asteroid.h"
#include <iostream>

using std::cout;
using std::endl;

Asteroid::Asteroid()
{
		mText = new sf::Texture();

		mText->loadFromFile("asteroid-texture.png");

		mBody.setTexture(*mText);
}

Asteroid::Asteroid(sf::Texture * texture)
{
	mBody.setTexture(*texture);
	mText = texture;
}

sf::Sprite & Asteroid::getBody()
{
	return mBody;
}

Asteroid::~Asteroid()
{
	delete mText;
}