#include "Food.h"
#include "Snake.h"
Food globfood;

Food* Food_create(Point2D _position)
{
    globfood.position=_position;
    return &globfood;
}

void Food_destroy(Food* food)
{
    //Does nothing, food is currently statically allocated
}

int Food_handleCollision(Snake* snake,Food* food)
{
    return Point2D_cmp(Snake_getHead(snake),&food->position)==0;
}