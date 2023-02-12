#include "TestScene.h"
#include <cassert>
TestScene::TestScene(SDL_Renderer** r, GameStateManager& GSM)
    :
    GSM(GSM),
    renderer(r)
{
    for (int i = 0; i <= 1000; i += 50) {
        for (int j = 0; j <= 800; j += 50) {
            if(i==50||j==50||i==900||j==700)
                wallEnts.push_back(new Wall(i, j, 50, 50));
        }
        //wallEnts.push_back(new Wall(i, 0, 50, 50));
    }
    pause = false;
    apple.generate(snake.body);
    assert(r!=NULL);
}

void TestScene::logic()
{
    if (!pause) {
        if (snake.body[snake.head].x == apple.rect.x && snake.body[snake.head].y == apple.rect.y) {
            apple.generate(snake.body);
            snake.newTail();
        }
        snake.logic();

        if (snake.endGame) {
            pause = true;
            //GSM.changeState(new TestScene(renderer, GSM));
            return;
        }

        if (snake.body[snake.head].x <= 50 || snake.body[snake.head].x >= 900) {
            GSM.changeState(new TestScene(renderer, GSM));
            return;
        }
        if (snake.body[snake.head].y <= 50 || snake.body[snake.head].y >= 700) {
            GSM.changeState(new TestScene(renderer, GSM));
            return;
        }
    }
}

void TestScene::render()
{
    for (auto i : wallEnts)
    {
        i->render(*renderer);
    }
    snake.render(*renderer);
    apple.render(*renderer);
}

void TestScene::handleInput(SDL_Event &e)
{
    if (e.type == SDL_KEYDOWN)
    {
        switch (e.key.keysym.sym)
        {
        case SDLK_p: GSM.changeState(new TestScene(renderer,GSM)); break;
        }
    }
    snake.handleInput(e);
}


TestScene::~TestScene()
{
    

}