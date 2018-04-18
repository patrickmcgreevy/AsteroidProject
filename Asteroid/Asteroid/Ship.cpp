#pragma once
#include "Ship.h"

#define X_AXIS_MID 250
#define Y_AXIS_MID 250

Ship::Ship()
{
	// Sets the sprite texture
	mText = new sf::Texture();
	mText->loadFromFile("ship-base-texture.png");
	mBody.setTexture(*mText);

	mBody.setPosition(X_AXIS_MID, Y_AXIS_MID);
}

Ship::~Ship()
{
	delete mText;
}

sf::Sprite & Ship::getBody()
{
	return mBody;
}

void Ship::rotateCW()
{
	mBody.rotate(2);
}

void Ship::rotateCounterCW()
{
	mBody.rotate(-2);
}