#pragma once

#define MAX_SNAKE_LENGTH 1024

#include "Point2D.h"

typedef struct 
{
    Point2D segments[MAX_SNAKE_LENGTH];
    Vector2D velocity;
} Snake;

Snake* Snake_create(int x, int y);
int Snake_delete(Snake* sn);
void Snake_setVelocity(Vector2D newVelocity);
void Snake_tickUpdate();
void Snake_extend();
Point2D* Snake_getHead(Snake* snake);
bool Snake_selfIntersects(Snake* snake);