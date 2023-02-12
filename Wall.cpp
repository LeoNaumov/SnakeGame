#include "Wall.h"

void Wall::render(SDL_Renderer* r)
{
	SDL_SetRenderDrawColor(r, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(r, &rect);
}