#pragma once
#include "Point2D.h"
#include <stdbool.h>

void Collisions_detect();
int Collider_Register(int objectID,Point2D* p);
void Collider_Deregister(int colliderID);
bool Collider_Exists(int colliderID);
void Collisions_detect();
