#pragma once
#include "BoundedObject.h"
#include <SFML/Graphics.hpp>

class SlopeObject : public BoundedObject
{
public:
	virtual void move() = 0; // Absolute virtual that each BoundedObject should implement
protected:
	sf::Vector2f mSlope; // So that the object knows how much to move along the x and y coordinates
};