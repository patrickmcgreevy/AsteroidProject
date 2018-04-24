#pragma once
#include "Stats.h"

Stats::Stats() {
	mFont.loadFromFile("Roboto-Regular.ttf");
	mText.setFont(mFont);
	mText.setCharacterSize(15);
	mText.setFillColor(sf::Color::White);
	mText.setString("Lives: 3\nScore: 0");
	mText.setStyle(sf::Text::Bold);
	mText.setPosition(10, 30);
}

Stats::~Stats() {

}

int Stats::getScore() {
	return mScore;
}

int Stats::getLives() {
	return mLives;
}


sf::Text& Stats::getText() {
	return mText;
}


void Stats::setScore(int newScore) {
	mScore = newScore;
}

void Stats::setLives(int newLives) {
	mLives = newLives;
}
