#pragma once

#include <stdbool.h>
#include <stdint.h>

typedef struct
{
  int16_t x;
  int16_t y; 
} Point2D;
#define Vector2D Point2D

bool Point2D_isValid(Point2D point);
