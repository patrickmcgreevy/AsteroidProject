#pragma once
#include <sstream>
#include "Ship.h"

using std::string;

class Stats {
public:
	Stats();
	~Stats();
	int getScore();
	int getLives();
	void setLives(int newLives);
	void setScore(int newScore);
	sf::Text& getText();
	void updateText();
private:
	std::ostringstream sStream;
	sf::Text mText;
	sf::Font mFont;
	int mScore;
	int mLives;
};