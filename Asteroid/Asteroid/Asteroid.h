#pragma once
#define _USE_MATH_DEFINES
#include "SlopeObject.h"
#include <cmath>
#include <iostream>
#include <random>
#include "Universal.h"

class Asteroid : public SlopeObject
{
public:
	Asteroid(); // For tests. don't call. destructor doesnt work anymore
	Asteroid(sf::Texture * texture);
	Asteroid(sf::Texture * texture, sf::Vector2f & size);
	~Asteroid();

	sf::Sprite & getBody();
	sf::Vector2f & getSlope();

	sf::Texture * getmText();
	int getParts(); // How many more times the asteroid may be split
	void setParts(int n); // Sets the number of times the asteroid may be split

	void updateSlope(double theta); // For setting direction of the mini stroids
	void updateSlope(); // Don't call
	
	 
	void move(); // Changes the x and y coordinates of the object based on its slope and a modifier
private:
	sf::Texture *mText;
	int nParts; // The number of times the asteroid may be split
};