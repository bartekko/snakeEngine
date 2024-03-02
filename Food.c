#include "Food.h"
#include "Snake.h"
#include "stdlib.h"
#include "Collision.h"

void* Food_create(Point2D position)
{
    Food* food=malloc(sizeof(Food));
    food->position=position;
    Collider_Register(1,&food->position);
    return food;
}

void Food_destroy(Food* food)
{
    free(food);
}

bool Food_msgHandler(void* fd,Message* msg)
{
    Food* food=(Food*)fd;

    switch (msg->type)
    {
    case MT_COLLISION:
        msg_Collision col=msg->c.collision;
        if(GameObject_get(col.other)->ot==OT_SNAKE)
        {
            food->position.x=rand()%30+1;
            food->position.y=rand()%30+1;
        }
        return true;

    default:
        return false;
    }
}

int Food_handleCollision(Snake* snake,Food* food)
{
    return Point2D_cmp(Snake_getHead(snake),&food->position)==0;
}