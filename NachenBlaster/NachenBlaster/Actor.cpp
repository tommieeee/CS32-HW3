#include "Actor.h"
#include "StudentWorld.h"

// Students:  Add code to this file, Actor.h, StudentWorld.h, and StudentWorld.cpp

Actor::Actor(int imageID, int startX, int startY, int startDirection, double size, int depth)
	:GraphObject(imageID, startX, startY, startDirection, size, depth)
{
}

Star::Star(int imageID, int startX, int startY, int startDirection, double size, int depth)
	: Actor(imageID, startX, startY, startDirection, size, depth)
{
}

void Star::doSomething() 
{
	double x = getX();
	double y = getY();
	moveTo(x - 1, y);
	
}