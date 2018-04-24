#pragma once
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
private:
	sf::Text mText;
	sf::Font mFont;
	string sText;
	string mString1;
	string mString2;
	int mScore;
	int mLives;
};