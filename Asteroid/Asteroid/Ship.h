#pragma once
#include <SFML\Graphics.hpp>

class Ship
{
public:
	Ship();
	~Ship();

	sf::Sprite & getBody();
	void rotateCW();
	void rotateCounterCW();
private:
	sf::Sprite mBody;
	sf::Texture *mText;
};