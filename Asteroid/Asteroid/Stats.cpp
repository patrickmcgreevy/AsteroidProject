#pragma once
#include "Stats.h"

Stats::Stats() {
	mFont.loadFromFile("Roboto-Regular.ttf");
	mText.setFont(mFont);
	mText.setCharacterSize(15);
	mText.setFillColor(sf::Color::White);
	mText.setStyle(sf::Text::Bold);
	mText.setPosition(10, 30);
	mLives = 3;
	mScore = 0;
	updateText();
	
}

Stats::~Stats() {

}

void Stats::updateText() {
	sStream.str("");
	sStream << "Lives : " << mLives << "\nScore : " << mScore;
	mText.setString(sStream.str());
}

int Stats::getScore() {
	return mScore;
	updateText();
}

int Stats::getLives() {
	return mLives;
}


sf::Text& Stats::getText() {
	return mText;
}


void Stats::setScore(int newScore) {
	mScore = newScore;
	updateText();
}

void Stats::setLives(int newLives) {
	mLives = newLives;
	updateText();
}
