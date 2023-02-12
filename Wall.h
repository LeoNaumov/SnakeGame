#pragma once
#include "Singletons.h"

struct Wall
{
	SDL_Rect rect;
	int posX;
	int posY;
	Wall(int x,int y,int w,int h) {
		rect.x = x;
		rect.y = y;
		rect.w = w;
		rect.h = h;
		posX = x;
		posY = y;
	}
	void render(SDL_Renderer* r);
};

