#include "Snake.h"
#include <string.h>
#include <ncurses.h>

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
    //Disallow reversing direction until we can handle it properly
    if(globsnake.velocity.x==-newVelocity.x
       && globsnake.velocity.y==-newVelocity.y)
    {
        return;
    }
    if(Point2D_isValid(newVelocity))
    {
        globsnake.velocity.x=newVelocity.x;
        globsnake.velocity.y=newVelocity.y;
    }
}

void Snake_tickUpdate()
{
    for(int i=0;i<MAX_SNAKE_LENGTH-1;i++)
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
        if(Snake_selfIntersects(&globsnake))
        {
            globsnake.segments[2]=Point2D_invalid;
        }

    }
}

void Snake_extend()
{
    memmove(&globsnake.segments[1],&globsnake.segments[0],MAX_SNAKE_LENGTH-1);
}

Point2D* Snake_getHead(Snake* snake)
{
    for(int i=0;i<MAX_SNAKE_LENGTH-1;i++)
    {
        if(!Point2D_isValid(snake->segments[i+1]))
        {
            return &snake->segments[i];
        }
    }
    return &snake->segments[MAX_SNAKE_LENGTH-1];
}

bool Snake_selfIntersects(Snake* snake)
{
    for(int i=0;Point2D_isValid(snake->segments[i+1]);i++)
    {
        int col_enable=false;
        for(int j=i-1;j>=0;j--)
        {
            if(Point2D_cmp(&snake->segments[i],&snake->segments[j])==0){
                if(col_enable)return true;
            }
            else{
                col_enable=true;
            }
        }
    }
    return false;
}

int Snake_getLength()
{
    for( int i=0;i<1023;i++)
    {
        if(!Point2D_isValid(globsnake.segments[i]))
        {
            return i-1;
        }
    }
    return MAX_SNAKE_LENGTH;
}