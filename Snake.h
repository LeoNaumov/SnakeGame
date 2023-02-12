#pragma once
#include "Singletons.h"
#include "Timer.h"

enum Dirs {
	West,
	North,
	East,
	South
};
enum Dir {
	Left,
	Right,
	Down,
	Up
};

struct Snake
{
	std::vector<SDL_Rect> body;
	LTimer timer;
	int dir;
	const int head = 0;
	bool tail;
	bool endGame;
	bool once = true;

	Snake();
	
	void newTail();
	void handleInput(SDL_Event &e);
	void logic();
	void render(SDL_Renderer *);
};

