#define SNAKE_SEGMENT_SYMBOL '*'
#include <ncurses.h>

#include "Snake.h"
#include "Render_objects.h"

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