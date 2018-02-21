#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"

// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp

class Actor : public GraphObject
{
public:
	Actor(int imageID, int startX, int startY, int startDirection, double size, int depth); //constructor
	virtual void doSomething() { return; }
	virtual ~Actor() {}
};

class Star : public Actor
{
public:
	Star(int imageID, int startX, int startY, int startDirection, double size, int depth);
	virtual ~Star() {}
	virtual void doSomething();
};

#endif // ACTOR_H_
