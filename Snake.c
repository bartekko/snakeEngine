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
    globsnake.velocity.x=newVelocity.x;
    globsnake.velocity.y=newVelocity.y;
}

void Snake_tickUpdate()
{
    for(int i=0;i<1023;i++)
    {
        if(Point2D_isValid(globsnake.segments[i+1])){
            globsnake.segments[i].x=globsnake.segments[i+1].x;
            globsnake.segments[i].y=globsnake.segments[i+1].y;

        }
        else{ //wait, what convention did I agree on with myself?
            globsnake.segments[i].x+=globsnake.velocity.x;
            globsnake.segments[i].y+=globsnake.velocity.y;
            return;
        }

    }
}

void Snake_extend()
{
    memmove(&globsnake.segments[1],&globsnake.segments[0],1023);
}
