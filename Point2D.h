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
bool Point2D_isValid(Point2D point);
int Point2D_cmp(Point2D* a,Point2D* b);