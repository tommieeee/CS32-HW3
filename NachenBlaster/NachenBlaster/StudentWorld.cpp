#include "StudentWorld.h"
#include "GameConstants.h"
#include <string>
#include <vector>
#include <algorithm>
#include "Actor.h"
using namespace std;

GameWorld* createStudentWorld(string assetDir)
{
	return new StudentWorld(assetDir);
}

// Students:  Add code to this file, StudentWorld.h, Actor.h and Actor.cpp

StudentWorld::StudentWorld(string assetDir)
: GameWorld(assetDir)
{
}

int StudentWorld::init()
{
	for (int i = 0; i < 30; i++)
	{
		int x = randInt(0, 255);
		int y = randInt(0, 255);
		double size = (randInt(5, 50)/ (double)100);
		act.push_back(new Star(IID_STAR, x, y, 0, size, 3));
	}
    return GWSTATUS_CONTINUE_GAME;
}

int StudentWorld::move()
{
	if (randInt(1,15) == 6)
	{
		int y = randInt(0, 255);
		double size = (randInt(5, 50) / (double)100);
		int x = 255;
		act.push_back(new Star(IID_STAR, x, y, 0, size, 3));
	}
	for (int i = 0; i < act.size(); i++)
	{
		act[i]->doSomething();
	}

	for (int i = 0; i < act.size(); i++)
	{
		if (act[i]->getX() < 0)
		{
			delete act[i];
			act.erase(act.begin() + i);
		}
	}

    // This code is here merely to allow the game to build, run, and terminate after you hit enter.
    // Notice that the return value GWSTATUS_PLAYER_DIED will cause our framework to end the current level.
    //decLives();
    //return GWSTATUS_PLAYER_DIED;
	return 1;
}

void StudentWorld::cleanUp()
{
	for (int i = act.size() - 1; i >= 0; i--)
	{
		delete act[i];
		act.pop_back();
	}
}
