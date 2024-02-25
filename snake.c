#define KEY_ESC 27
#include <ncurses.h>

#include "Snake.h"
#include "Renderer.h"
#include "Render_objects.h"

Point2D ktov(int key);

int main(int argc, char** argv)
{
    Renderer_initialize();
    Snake* snake = Snake_create(5,40);
    Snake_extend();
    Snake_extend();
    Snake_extend();
    Snake_extend();
    Snake_extend();
    int c;
    do 
    {  
        c=getch();        
        Snake_setVelocity(ktov(c));
        Snake_tickUpdate();
        clear();
        Render_Snake(snake);
    }while(c!=KEY_ESC);
//Process game logic
//Use game state to update screen

//Wait until next game tick
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
        ret.x=0;
        ret.y=0;
        break;
    }
    return ret;
}