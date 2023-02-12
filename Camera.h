#pragma once
#include "Shape.h"

class Camera
{
	int SW;
	int SH;

	int LW;
	int LH;

	Shape rect;

public:
	int x, y;

	Camera(int,int,int,int);

	void logic(int pX,int pY,int,int);

	int getX();
	int getY();

	SDL_Rect& getRect();
};

