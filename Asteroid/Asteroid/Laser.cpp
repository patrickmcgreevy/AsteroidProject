#pragma once
#include "Laser.h"

#define SCREEN_MAX_LEN 640

Laser::Laser(sf::Texture * pText, sf::Vector2f slope, sf::Vector2f initialPos)
{
	//std::cout << "Inside Laser constructor." << std::endl;
	mRangeExceded = false;

	mpText = pText;
	mBody.setTexture(*mpText);

	mSlope = slope;

	mInitialPos = initialPos;
	mBody.setPosition(mInitialPos);
}

Laser::~Laser()
{
	//std::cout << "Inside Laser destructor." << std::endl;
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
	double dX, dY, dHyp;

	mBody.move(mSlope.x * (WINDOW_WIDTH / 250), mSlope.y * (WINDOW_HEIGHT / 250));

	dX = mBody.getPosition().x - mInitialPos.x;
	dY = mBody.getPosition().y - mInitialPos.y;
	dHyp = pow(dX * dX + dY * dY, 1 / 2);

	/*curX = mBody.getPosition().x;
	curY = mBody.getPosition().y;
	curHyp = pow(curX*curX + curY*curY, 1 / 2);*/
	/*if (dHyp >= SCREEN_MAX_LEN)
	{
		mRangeExceded = true;
	}*/
	if (dX > WINDOW_WIDTH || dX < -WINDOW_WIDTH || dY > WINDOW_HEIGHT || dY < -WINDOW_HEIGHT)
	{
 		mRangeExceded = true;
	}
}