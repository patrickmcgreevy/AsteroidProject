#pragma once
#include "BoundedObject.h"
#include <SFML/Graphics.hpp>

class SlopeObject : public BoundedObject
{
public:
	virtual void move() = 0;
protected:
	sf::Vector2f mSlope;
};