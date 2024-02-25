#define EXIT_KEY 'q'
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#include "Snake.h"
#include "Renderer.h"
#include "Render_objects.h"
#include "Food.h"

Point2D ktov(int key);

int main(int argc, char** argv)
{
    Renderer_initialize();
    srand(time(NULL));
    Snake* snake = Snake_create(5,20);
    Snake_extend();
    Snake_extend();
    Snake_extend();
    Snake_extend();
    Snake_extend();
    Point2D p={.x=rand()%20,.y=rand()%20};
    Food* food=Food_create(p);
    int c;
    bool exit=false;
    do 
    {  
        //Input
        c=Renderer_scanInput(); 

        //Game Logic
        Snake_setVelocity(ktov(c));
        
        Snake_tickUpdate();
        
        if(Food_handleCollision(snake,food))
        {
            Snake_extend();
            Point2D p={.x=rand()%20,.y=rand()%20};
            Food_destroy(food);
            food=Food_create(p);
        }
        //Rendering
        Renderer_nextFrame();
        Render_Snake(snake);
        Render_Food(food);
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