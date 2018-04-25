#pragma once
#define _USE_MATH_DEFINES
#include "SlopeObject.h"
#include <SFML\Graphics.hpp>
#include <cmath>
#include "Universal.h"

class Ship : public SlopeObject
{
public:
	Ship();
	~Ship();

	sf::Sprite & getBody();

	void updateSlope(double theta); // Pass in the rotation of mBody
	void updateSlope(); // Changes the slope based on the sprite's rotation
	void swapTexture(); // Swaps the textures of the ship

	sf::Vector2f & getSlope(); // Retuns the vector that is the ship's slope
	const sf::Vector2f & getPos(); // returns the vector cooresponding to the ship's posiiton
	sf::Vector2f getTip(); // Returns a vector cooresponding to the tip of the ship's texture

	void move(); // Changes the x and y coordinates of the object based on its slope and a modifier

	void rotateCW(); // Rotate clock wise about the center of the ship; currently not working as intended
	void rotateCounterCW(); // Rotate counter clock wise about the center of the ship; currently not working as intended
private:
	sf::Texture *mText;
	sf::Texture *mText2;
};