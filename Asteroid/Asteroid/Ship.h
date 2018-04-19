#pragma once
#define _USE_MATH_DEFINES
#include <SFML\Graphics.hpp>
#include <cmath>

class Ship
{
public:
	Ship();
	~Ship();

	sf::Sprite & getBody();

	void updateSlope(double theta); // Pass in the rotatoin of mBody
	void updateSlope();
	void swapTexture();

	void move();

	void rotateCW(); // Rotate clock wise about the center of the ship; currently not working as intended
	void rotateCounterCW(); // Rotate counter clock wise about the center of the ship; currently not working as intended
private:
	sf::Sprite mBody;
	sf::Texture *mText;
	sf::Texture *mText2;
	sf::Vector2f mSlope; // Length of vector should always be equal to one. Or maybe less. Should be constant?
};