#pragma once

#include "Point2D.h"

//Known limitations: Too many to list, a *big* rethink of the entire system is required

typedef enum{
    ST_POINT,
    ST_LINE,
    ST_RECT,
//    ST_CIRCLE,
    ST_COUNT,
    ST_INVALID,
} ShapeType;

typedef struct Line2D{
    Point2D a;
    Point2D b;
} Line2D;

typedef struct Rectangle2D{
    Point2D bottomLeft;
    Point2D topRight;
} Rectangle2D;

/*
typedef struct Circle2D{
    Point2D center;
    double radius;
} Circle2D;
*/
typedef struct Shape{
    ShapeType ShapeType;
    union{
        Point2D point2D;
        Line2D line2D;
        Rectangle2D rect2D;
//        Circle2D circle2D;
    } c;

} Shape;

#define Shape_invalid (Shape){.ShapeType==ST_INVALID};
bool Shape_isValid(const Shape* s);
bool Shape_intersects(const Shape* a,const Shape* b);

//returns central point of given shape;
Point2D Shape_Center(Shape* s);

//Returns distance from center to the furthest point still part of shape in dir direction
double Shape_Extent(Shape* s, Vector2D dir);

//returns true if s contains p, false otherwise.
//Undefined if either is invalid.
bool Shape_Contains(Shape* s, Point2D* p);