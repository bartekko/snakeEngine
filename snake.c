#include <ncurses.h>

#include "Snake.h"
#include "Renderer.h"

int main(int argc, char** argv)
{
    Renderer_initialize();

//Repeat until escape key pressed:
//Get input 
//Process game logic
//Use game state to update screen

//Wait until next game tick

    getch();
    Renderer_close();    
    return 0;

}