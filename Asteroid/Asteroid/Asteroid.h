#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Asteroid 
{
public:
	Asteroid();
	Asteroid(sf::Texture & texture);

	sf::Sprite & getBody();
private:
	sf::Sprite mBody;
};