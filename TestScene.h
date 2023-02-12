#pragma once
#include "GameState.h"
#include "GameStateManager.h"
#include "Wall.h"
#include "Snake.h"
#include "Apple.h"

struct TestScene : public GameState
{
	void logic();
	void render();
	void handleInput(SDL_Event& e);

	TestScene(SDL_Renderer** r, GameStateManager& GSM);
	~TestScene();

	int pause;
	SDL_Renderer** renderer;
	GameStateManager& GSM;

	std::vector<Wall*> wallEnts;
	Snake snake;
	Apple apple;
};

