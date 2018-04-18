#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <iostream>
#include <random>

class Asteroid 
{
public:
	Asteroid();
	Asteroid(sf::Texture * texture, sf::Vector2f & size);
	~Asteroid();

	sf::Sprite & getBody();
	sf::Vector2f & getSlope();
private:
	sf::Sprite mBody;
	sf::Texture *mText;
	sf::Vector2f mSlope;
};