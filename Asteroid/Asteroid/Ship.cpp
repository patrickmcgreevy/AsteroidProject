#pragma once
#include "Ship.h"
#include "Universal.h"

// Make these equal to half the window size?
#define X_AXIS_MID 250
#define Y_AXIS_MID 250

Ship::Ship()
{
	// Sets the sprite texture
	
	mText = new sf::Texture();
	mText->loadFromFile("ship-base-texture.png");

	mBody.setTexture(*mText);
	mBody.setRotation(1);

	// Sets the position of the sprite and the scale and the direction of the vector
	mBody.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	updateSlope();
	mBody.setOrigin(19, 33.5);
	//updateSlope(mBody.getRotation());
	/*mSlope.x = cos(mBody.getRotation());
	mSlope.y = sin(mBody.getRotation());*/
}

Ship::~Ship()
{
	delete mText;
}

sf::Sprite & Ship::getBody()
{
	return mBody;
}

sf::Vector2f & Ship::getSlope()
{
	return mSlope;
}
const sf::Vector2f & Ship::getPos()
{
	return mBody.getPosition();
}

void Ship::updateSlope(double theta) // theta is in degrees
{
	theta = theta * (M_PI / 180); // conversion to radians
	mSlope.y = cos(theta); 
	mSlope.x = sin(theta);
}


void Ship::updateSlope() // theta is in degrees
{
	double theta = mBody.getRotation() * (M_PI / 180); // conversion to radians
	mSlope.y = (-1) * cos(theta) / 10;
	mSlope.x = sin(theta) / 10;
}

void Ship::rotateCW()
{
	//double vLen = ((mSlope.x) ^ 2 + (mSlope.y) ^ 2) ^ (1 / 2);
	//double vLen = 
	mBody.rotate(.25);
	//sf::Vector2f newPos(mBody.getPosition().x + 21 * (1 - cos(mBody.getRotation() * (M_PI / 180))), mBody.getPosition().y + 21 * sin(mBody.getRotation() * (M_PI / 180)));
	//sf::Vector2f pUpdate = mBody.getPosition();
	/*pUpdate.x += cos(mBody.getRotation() * (M_PI / 180));
	pUpdate.y += sin(mBody.getRotation() * (M_PI / 180));*/
	updateSlope();

	//mBody.setPosition(newPos);
}

void Ship::rotateCounterCW()
{
	sf::Vector2f pUpdate = mBody.getPosition();
//	pUpdate.x += (mBody.getTexture()->getSize().x / 2) * cos(mBody.getRotation() * (M_PI / 180));
//	pUpdate.y += (mBody.getTexture()->getSize().y / 2) * sin(mBody.getRotation() * (M_PI / 180));
	mBody.rotate(-.25);

	/*pUpdate.x -= cos(mBody.getRotation() * (M_PI / 180));
	pUpdate.y -= sin(mBody.getRotation() * (M_PI / 180));*/

	updateSlope();

//	mBody.setPosition(pUpdate);
}

void Ship::move()
{
	// Update texture to rocket firing mode
	//swapTexture();
	mBody.move(mSlope.x * (WINDOW_WIDTH / 250), mSlope.y * (WINDOW_HEIGHT / 250));
}

void Ship::swapTexture()
{
	if (mBody.getTexture() == mText)
	{
		mBody.setTexture(*mText2);
	}
	else
	{
		mBody.setTexture(*mText);
	}
}

// return a vector with the position of the tip
sf::Vector2f Ship::getTip() {
	float newx = this->getPos().x + 18*cos(mBody.getRotation() * (M_PI / 180));
	float newy = this->getPos().y + 18 * sin(mBody.getRotation() * (M_PI / 180));
	sf::Vector2f tip(newx, newy);
	return tip;
}