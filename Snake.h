#include "Point2D.h"
typedef struct
{
    Point2D* segmentsArray;
    Vector2D velocity;
} Snake;

Snake Snake_create(int x, int y);
int Snake_delete(Snake sn);
void Snake_setVelocity(Vector2D newVelocity);
void Snake_tickUpdate();
void Snake_extend();
