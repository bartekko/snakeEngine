#include "Snake.h"
#include <string.h>

static Snake globsnake;
Snake* Snake_create(int x, int y)
{
    globsnake.segments[0].x=x;
    globsnake.segments[0].y=y;

    //invalidate all other segments
    for(int i=1;i<1024;i++)
    {
        globsnake.segments[i].x=INT16_MAX;
    }
    return &globsnake;
}

int Snake_delete(Snake* sn)
{
    //Do nothing, currently the snake is statically allocated
}
void Snake_setVelocity(Vector2D newVelocity)
{
    //TODO
}
void Snake_tickUpdate()
{
    //TODO
}
void Snake_extend()
{
    memmove(&globsnake.segments[1],&globsnake.segments[0],1023);
    globsnake.segments[0].x=globsnake.segments[1].x-1;
    globsnake.segments[0].y=globsnake.segments[1].y;
}
