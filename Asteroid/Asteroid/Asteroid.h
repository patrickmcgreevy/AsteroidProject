#pragma once
#define _USE_MATH_DEFINES
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <cmath>
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

	void updateSlope(double theta); // For setting direction of the mini stroids
	void updateSlope(); // Don't call
private:
	sf::Sprite mBody;
	sf::Texture *mText;
	sf::Vector2f mSlope;
};