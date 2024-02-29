#define MAX_SNAKE_LENGTH 1024
#include "Snake.h"
#include "Point2D.h"
#include "GameObject.h"
#include "stdlib.h"


#include <string.h>
#include <ncurses.h>

void* Snake_create(Point2D p)
{
    Snake* res=malloc(sizeof(Snake));
    res->segments[0].x=p.x;
    res->segments[0].y=p.y;
    res->velocity.x=1;
    res->segments[1].x=INT16_MAX;
    return (void*)res;
}

int Snake_delete(Snake* snake)
{
    free(snake);
}

void Snake_setVelocity(Snake* snake, Vector2D newVelocity)
{
    //Disallow reversing direction until we can handle it properly
    if(snake->velocity.x==-newVelocity.x
       && snake->velocity.y==-newVelocity.y)
    {
        return;
    }
    if(Point2D_isValid(newVelocity))
    {
        snake->velocity.x=newVelocity.x;
        snake->velocity.y=newVelocity.y;
    }
}

void Snake_tickUpdate(Snake* snake)
{
    for(int i=0;i<MAX_SNAKE_LENGTH-1;i++)
    {
        if(Point2D_isValid(snake->segments[i+1])){
            snake->segments[i].x=snake->segments[i+1].x;
            snake->segments[i].y=snake->segments[i+1].y;

        }
        else{ //wait, what convention did I agree on with myself?
            snake->segments[i].x+=snake->velocity.x;
            snake->segments[i].y+=snake->velocity.y;
            return;
        }
        if(Snake_selfIntersects(snake))
        {
            snake->segments[2]=Point2D_invalid;
        }

    }
}

void Snake_extend(Snake* snake)
{
    memmove(&snake->segments[1],&snake->segments[0],sizeof(Point2D)*(MAX_SNAKE_LENGTH-1));
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

int Snake_getLength(Snake* sn)
{
    for( int i=0;i<1023;i++)
    {
        if(!Point2D_isValid(sn->segments[i]))
        {
            return i-1;
        }
    }
    return MAX_SNAKE_LENGTH;
}