#pragma once
#include <SFML\Graphics.hpp>
#include <cmath>
#include <iostream>
#include "Universal.h"

class Laser
{
public:
	Laser(sf::Texture * pText, sf::Vector2f slope, sf::Vector2f initialPos);
	~Laser();
	sf::Sprite & getBody();

	bool checkRange(); // Ensures that the Laser object has not gone too far

	void move(); // Changes the x and y coordinates of the object based on its slope and a modifier
private:
	sf::Sprite mBody;
	sf::Texture *mpText;
	sf::Vector2f mSlope;
	sf::Vector2f mInitialPos;
	bool mRangeExceded;
};