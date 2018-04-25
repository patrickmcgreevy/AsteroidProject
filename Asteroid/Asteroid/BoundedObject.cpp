#pragma once
#include "BoundedObject.h"

void BoundedObject::boundCheck()
{
	double top = mBody.getPosition().y,
	 bot = mBody.getPosition().y + mBody.getTexture()->getSize().y,
	 left = mBody.getPosition().x,
	 right = mBody.getPosition().x + mBody.getTexture()->getSize().x;

	if (right < 0) {
		mBody.setPosition(WINDOW_WIDTH, mBody.getPosition().y); // Moves the object to the right side
	}
	else if (left > WINDOW_WIDTH) { 
		mBody.setPosition(-1.0 * mBody.getTexture()->getSize().x, mBody.getPosition().y); // Moves the object to the left side
	}

	if (top > WINDOW_HEIGHT) { // Moves the object to the top of the window
		mBody.setPosition(mBody.getPosition().x, -1.0 * mBody.getTexture()->getSize().y);
	}
	else if (bot < 0) {
		mBody.setPosition(mBody.getPosition().x, WINDOW_HEIGHT); // Moves the object to the bottom of the window
	}
}