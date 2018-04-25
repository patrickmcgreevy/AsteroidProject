// overall wrapper class
// controles all rendering and executes all motion
// detects interactions and initiates proper reactions

#pragma once
#include "Ship.h"
#include "Laser.h"
#include "Asteroid.h"
#include "List.h"
#include "Universal.h"
#include <cmath>
#include "stats.h"

class GameWrapper
{
public:
	GameWrapper();
	~GameWrapper();

	void runGame(); // Runs the whole game
	//void garbageCollector();

	void splitAsteroid(Asteroid * oldAst); // Makes two new asteroids based on the parameter asteroid
	bool checkSplit(Asteroid * oldAst); // Returns true or false depending on 
	
	double checkDist(sf::Vector2f & v1, sf::Vector2f & v2); // Finds the magnitude of the vector which may be drawn between two points

	bool checkCollision(Laser * laser, Asteroid * asteroid); // checks for laser vs asteroid collision; maybe kinda works
	bool checkCollision(Ship & ship, Asteroid * asteroid); // checks for ship vs asteroid collision; maybe kinda works

	void GameWrapper::refreshLevel(int & n, sf::Texture * pText); // initializes 4 + n asteroids

	void drawAsteroidList(sf::RenderWindow & w); // Draws every Asteroid object in the mAstList
	void drawLaserList(sf::RenderWindow & w); // Draws every Laser object in the mLaserList

	// moves a whole list of the type
	void moveLaserList(); // Moves every Laser in mLaserList according to its individual slope
	void moveAsteroidList(); // Moves every Asteroid in mAstList according to its individual slope

	void astListBoundCheck(); // Checks that every instantiated Asteroid has not left the bounds of the window; if any have left they "roll over" to the other side

	void mainMenu(); // Runs the main game menu
	void printInstructions(); // Prints the instructions on how to play the game

private:
	sf::Texture * mpAstText;
	sf::Texture * mpLaserText;
	sf::Texture * mpBorderText;
	sf::RenderWindow mWindow;
	Stats mScore;
	List<Asteroid *> mAstList;
	List<Laser *> mLaserList;
	sf::Event mEvent;
};