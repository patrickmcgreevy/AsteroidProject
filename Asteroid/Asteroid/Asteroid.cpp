#pragma once
#include "Asteroid.h"

#define SLOPE_DIVISOR 10000
#define SCALE_DIVISOR 2

using std::cout;
using std::endl;

Asteroid::Asteroid()
{
	// Sets the texture of the sprite
	mText = new sf::Texture();
	mText->loadFromFile("asteroid-texture.png");
	mBody.setTexture(*mText);

	// Sets the slope to a random vector w/ dX and dY less than 1
	mSlope.x = (float)(rand() % 1000) / SLOPE_DIVISOR;
	mSlope.y = (float)(rand() % 1000) / SLOPE_DIVISOR;
	cout << "Slope: " << mSlope.x << ", " << mSlope.y << endl;
}

Asteroid::Asteroid(sf::Texture * texture) // Pass in pointer to spawning asteroid's texture and the asteroid's sprite's vector
{
	mBody.setTexture(*texture);
	mText = texture;

	// Sets the slope to a random vector w/ dX and dY less than 1
	mSlope.x = (float)(rand() % 1000) / SLOPE_DIVISOR;
	mSlope.y = (float)(rand() % 1000) / SLOPE_DIVISOR;
	cout << "Slope: " << mSlope.x << ", " << mSlope.y << endl;
}

// For creating a smaller asteroid upon the destruction of the bigger one
Asteroid::Asteroid(sf::Texture * texture, sf::Vector2f & size) // Pass in pointer to spawning asteroid's texture and the asteroid's sprite's vector
{
	mBody.setTexture(*texture);
	mText = texture;

	mBody.setScale(size.x / SCALE_DIVISOR, size.y / SCALE_DIVISOR); // Halves the size of the new asteroid
}

sf::Sprite & Asteroid::getBody()
{
	return mBody;
}

sf::Vector2f & Asteroid::getSlope()
{
	return mSlope;
}

void Asteroid::updateSlope(double theta)
{
	theta = theta * (M_PI / 180);
	mSlope.y = cos(theta);
	mSlope.x = sin(theta);
}

void Asteroid::updateSlope()
{
	double theta = mBody.getRotation() * (M_PI / 180);
	mSlope.y = cos(theta);
	mSlope.x = sin(theta);
}

Asteroid::~Asteroid()
{
	//delete mText;
}