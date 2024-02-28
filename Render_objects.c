#define SNAKE_SEGMENT_SYMBOL '*'
#define FOOD_SYMBOL          '#'
#define BORDER_SYMBOL        '='

#include <ncurses.h>
#include <stdlib.h>

#include "Snake.h"
#include "Render_objects.h"
#include "Hud.h"

void Render_Snake(Snake* snake)
{
    for(int i=0;i<MAX_SNAKE_LENGTH;i++)
    {
        Point2D segment;
        segment.x=snake->segments[i].x;
        segment.y=snake->segments[i].y;
        if(!Point2D_isValid(segment)) {break;}

        mvaddch(snake->segments[i].y,
                snake->segments[i].x,
                SNAKE_SEGMENT_SYMBOL);


    }
}

void Render_Food(Food* food)
{
    mvaddch(food->position.y,
            food->position.x,
            FOOD_SYMBOL);
}

void Render_Board(Board* board)
{
    //Top Border
    for(int i=0;i<board->size.x;i++)
    {
        mvaddch(0,i,BORDER_SYMBOL);
    }
    //Left Border
    for(int i=0;i<board->size.y;i++)
    {
        mvaddch(i,0,BORDER_SYMBOL);
    }
    //Right Border
    for(int i=0;i<board->size.x;i++)
    {
        mvaddch(i,board->size.x,BORDER_SYMBOL);
    }
    //Bottom Border
    for(int i=0;i<board->size.x;i++)
    {
        mvaddch(board->size.y,i,BORDER_SYMBOL);
    }
}

void Render_HUD(Hud* hud)
{
    mvprintw(0,0,"Score: %d",hud->curScore);
    mvprintw(1,0,"HScore: %d",hud->hiScore);
}