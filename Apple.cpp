#include "Apple.h"

Apple::Apple()
{
	srand(time(NULL));
	rect.w = 50;
	rect.h = 50;
}

bool Apple::check(int x,int y,std::vector<SDL_Rect> body)
{
	x *= 50;
	y *= 50;
	for (auto& i : body)
	{
		if (x == i.x && y == i.y) return false;
	}
	return true;
}
void Apple::generate(std::vector<SDL_Rect> body)
{
	int x = (rand() % 750/50) + 2;
	int y = (rand() % 550/50) + 2;
	while (!check(x, y, body)) {

		x = (rand() % 750/50) + 2;
		y = (rand() % 550/50) + 2;
	}
	rect.x = x*50;
	rect.y = y*50;
}

void Apple::render(SDL_Renderer *r)
{
	SDL_SetRenderDrawColor(r, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(r, &rect);
}