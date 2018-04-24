// Asteroid class contains information for display and motioin
// does not move itself

#pragma once
#define _USE_MATH_DEFINES
#include "SlopeObject.h"
//#include <SFML/Graphics.hpp>
//#include <SFML/Graphics/Sprite.hpp>
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
	int getParts();
	void setParts(int n);

	void updateSlope(double theta); // For setting direction of the mini stroids
	void updateSlope(); // Don't call
	
	 
	void move();
	//void boundCheck(); //inherits one from BoundedObject class
private:
	//sf::Sprite mBody;
	sf::Texture *mText;
	int nParts;
	//sf::Vector2f mSlope;
};