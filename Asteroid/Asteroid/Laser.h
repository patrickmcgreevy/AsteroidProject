#pragma once
#include <SFML\Graphics.hpp>
#include <cmath>

class Laser
{
public:
	Laser(sf::Texture * pText, sf::Vector2f slope, sf::Vector2f initialPos);

	sf::Sprite & getBody();

	void move();
private:
	sf::Sprite mBody;
	sf::Texture *mpText;
	sf::Vector2f mSlope;
	sf::Vector2f mInitialPos;
	bool mRangeExceded;
};