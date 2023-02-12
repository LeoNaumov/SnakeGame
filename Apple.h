#pragma once
#include "Singletons.h"
struct Apple
{
	SDL_Rect rect;
	
	Apple();

	void generate(std::vector<SDL_Rect>);
	void render(SDL_Renderer *);
	bool check(int,int,std::vector<SDL_Rect>);
};

