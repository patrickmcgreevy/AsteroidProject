#pragma once
#include <SFML\Graphics.hpp>
#include <cmath>
#include <iostream>

class Laser
{
public:
	Laser(sf::Texture * pText, sf::Vector2f slope, sf::Vector2f initialPos);
	~Laser();
	sf::Sprite & getBody();

	void move(); // shit works
private:
	sf::Sprite mBody;
	sf::Texture *mpText;
	sf::Vector2f mSlope;
	sf::Vector2f mInitialPos;
	bool mRangeExceded;
};