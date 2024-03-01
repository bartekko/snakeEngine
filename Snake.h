#pragma once

#define MAX_SNAKE_LENGTH 1024

#include "Point2D.h"
#include "GameObject.h"
typedef struct
{
    Point2D segments[MAX_SNAKE_LENGTH];
    Vector2D velocity;
} Snake;

void* Snake_create(Point2D p);
int Snake_delete(Snake* sn);
void Snake_setVelocity(Snake* sn, Vector2D newVelocity);
bool Snake_msgHandler(void* sn,Message* msg);
void Snake_extend(Snake* sn);
Point2D* Snake_getHead(Snake* snake);
bool Snake_selfIntersects(Snake* snake);
int Snake_getLength(Snake* sn);