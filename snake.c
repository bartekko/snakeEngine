#define EXIT_KEY 'q'
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#include "Snake.h"
#include "Renderer.h"
#include "Render_objects.h"
#include "Food.h"
#include "Board.h"

Point2D ktov(int key);
int snake_getScore();

int main(int argc, char** argv)
{
    Renderer_initialize();
    srand(time(NULL));

    Snake* snake = Snake_create(5,20);
    Board* board = Board_create((Point2D){.x=40,.y=20});
    Point2D p={.x=rand()%20,.y=rand()%20};
    Food* food=Food_create(p);
    Hud* hud=HUD_Create();
    int c;
    bool exit=false;

    do
    {
        //Input
        c=Renderer_scanInput();

        //Game Logic
        Snake_setVelocity(ktov(c));
        HUD_updateScore(snake_getScore());
        Snake_tickUpdate();

        if(Food_handleCollision(snake,food))
        {
            Snake_extend();
            Point2D p={.x=rand()%20,.y=rand()%20};
            Food_destroy(food);
            food=Food_create(p);

        }
        if(Board_SnakeCollision(board,snake))
        {
            Snake_delete(snake);
            Snake_create(rand()%20,rand()%20);
            Snake_setVelocity((Point2D){.x=0,.y=0});

        }

        //Rendering
        Renderer_nextFrame();
        Render_Snake(snake);
        Render_Food(food);
        Render_Board(board);
        Render_HUD(hud);
        Renderer_waitUntilNextFrame();

        if(c==EXIT_KEY) exit=true;

    }while(!exit);

    Snake_delete(snake);
    Food_destroy(food);
    Renderer_close();
    return 0;
}

Vector2D ktov(int c)
{
    Vector2D ret;
    switch (c)
    {
    case KEY_UP:
        ret.x=0;
        ret.y=1;
        break;

    case KEY_DOWN:
        ret.x=0;
        ret.y=-1;
        break;

    case KEY_LEFT:
        ret.x=-1;
        ret.y=0;
        break;

    case KEY_RIGHT:
        ret.x=1;
        ret.y=0;
        break;

    default:
        ret=Point2D_invalid;
        break;
    }
    return ret;
}

int snake_getScore()
{
    return Snake_getLength();
}
