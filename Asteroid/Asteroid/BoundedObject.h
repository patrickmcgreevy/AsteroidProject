#pragma once
#include <SFML\Graphics.hpp>
#include "Universal.h"

// Intended to ensure that some objects stay within the bounds of the window
class BoundedObject
{
public:
	virtual void boundCheck();	// Ensures that the Sprites stay within the defined window bounds
protected:
	sf::Sprite mBody;
};