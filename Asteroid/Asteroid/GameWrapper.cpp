#pragma once
#include "GameWrapper.h"

GameWrapper::GameWrapper()
{
	mpAstText = new sf::Texture();
	mpAstText->loadFromFile("asteroid-texture.png");

	mpLaserText = new sf::Texture();
	mpLaserText->loadFromFile("laster-texture.png");

	mpBorderText = new sf::Texture();
	mpBorderText->loadFromFile("border-texture.png");
}

GameWrapper::~GameWrapper()
{
	delete mpAstText;
	delete mpLaserText;
	delete mpBorderText;
}

void GameWrapper::runGame()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "Asteroid Game");
}