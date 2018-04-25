#pragma once
#include "Laser.h"

#define SCREEN_MAX_LEN 640

Laser::Laser(sf::Texture * pText, sf::Vector2f slope, sf::Vector2f initialPos)
{
	mRangeExceded = false;

	mpText = pText;
	mBody.setTexture(*mpText);

	mSlope = slope;

	mInitialPos = initialPos;
	mBody.setPosition(mInitialPos);
}

Laser::~Laser()
{
}

bool Laser::checkRange()
{
	return mRangeExceded;
}

sf::Sprite & Laser::getBody()
{
	return mBody;
}

void Laser::move()
{
	double dX, dY;

	mBody.move(mSlope.x * (WINDOW_WIDTH / 250), mSlope.y * (WINDOW_HEIGHT / 250));

	dX = mBody.getPosition().x - mInitialPos.x; // Sets the delta of x and y relative to their starting point
	dY = mBody.getPosition().y - mInitialPos.y;

	if (dX > WINDOW_WIDTH || dX < -WINDOW_WIDTH || dY > WINDOW_HEIGHT || dY < -WINDOW_HEIGHT)
	{
 		mRangeExceded = true;
	}
}