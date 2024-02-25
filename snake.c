#include <ncurses.h>

#include "Snake.h"
#include "Renderer.h"
#include "Render_objects.h"

int main(int argc, char** argv)
{
    Renderer_initialize();

//Temporary Testing area
    
    Snake* snake = Snake_create(10,10);
    for(int i=0; i<5;i++) Snake_extend();
    Render_Snake(snake);

    getch();
    Snake_delete(snake);


//Repeat until escape key pressed:
//Get input 
//Process game logic
//Use game state to update screen

//Wait until next game tick
    Renderer_close();    
    return 0;
}