#pragma once

#include "Snake.h"
#include "Point2D.h"

typedef struct{
    Point2D position;
} Food;

Food* Food_create(Point2D _position);
void Food_destroy(Food* food);
int Food_handleCollision(Snake* snake, Food* food);
