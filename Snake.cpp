#include "Snake.h"

Snake::Snake()
{
	SDL_Rect t1 = {500,600,49,49};
	SDL_Rect t2 = {550,600,49,49 };
	SDL_Rect t3 = {600,600,49,49 };

	body.push_back(t1);
	body.push_back(t2);
	body.push_back(t3);

	dir = West;
	timer.start();
	tail = false;
	endGame = false;
	once = true;
}

void Snake::handleInput(SDL_Event &e)
{
	std::cout << once;
	if (e.type == SDL_KEYDOWN)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_RIGHT: if (once == true && dir != West) { once = false;  dir = East; } break;
		case SDLK_LEFT: if (once == true && dir != East) { once = false; dir = West; }  break;
		case SDLK_DOWN: if (once && dir != North) { once = false;  dir = South; }break;
		case SDLK_UP:  if (once && dir != South) { once = false; dir = North; } break;
		}
	}
}

void Snake::logic()
{
	if (timer.getTicks() > 100) {

		once = true;
		SDL_Rect t1 = body[head];
		SDL_Rect t2;
		for (int i = head + 1; i < body.size(); i++) {
			t2 = body[i];
			body[i] = t1;
			t1 = t2;
		}
		if (tail) {
			SDL_Rect temp = t2;
			body.push_back(temp);
			tail = false;
		}
		if (dir == West) {
			body[head].x -= 50;
		}
		else if (dir == East) {
			body[head].x += 50;
		}
		else if (dir == South) {
			body[head].y += 50;
		}
		else if (dir == North) {
			body[head].y -= 50;
		}
		timer.start();
	}
	for (int i = 1; i < body.size();i++) {
		if (body[i].x == body[head].x && body[i].y == body[head].y)
			endGame = true;
	}
}

void Snake::render(SDL_Renderer* r) {
	for (auto &i:body) {
		SDL_SetRenderDrawColor(r, 0x00, 0xFF, 0x00, 0xFF);
		SDL_RenderFillRect(r, &i);
	}
}

void Snake::newTail()
{
	tail = true;
}