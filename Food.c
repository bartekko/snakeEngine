#include "Food.h"
#include "Snake.h"
#include "stdlib.h"

Food globfood;

void* Food_create(Point2D position)
{
    Food* food=malloc(sizeof(Food));
    food->position=position;
    return food;
}

void Food_destroy(Food* food)
{
    free(food);
}

int Food_handleCollision(Snake* snake,Food* food)
{
    return Point2D_cmp(Snake_getHead(snake),&food->position)==0;
}