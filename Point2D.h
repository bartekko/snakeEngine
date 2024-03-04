#pragma once

#include <stdbool.h>
#include <stdint.h>

typedef struct
{
  int16_t x;
  int16_t y;
} Point2D;
#define Vector2D Point2D

#define Point2D_invalid (Point2D){.x=INT16_MAX,.y=0};

//returns true if argument is a valid point
bool Point2D_isValid(Point2D point);

//returns 0 if points match
int Point2D_cmp(Point2D* a,Point2D* b);

//returns square of distance between two points
double Point2D_distsq(Point2D* a,Point2D* b);

//returns distance between two points
double Point2D_dist(Point2D* a,Point2D* b);

//returns direction of point to relative to from
Vector2D Point2D_getDirection(Point2D* from, Point2D* to);