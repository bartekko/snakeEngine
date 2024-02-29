#pragma once

#include "Point2D.h"

typedef struct
{
    int curScore;
    int hiScore;
} Hud;

Hud* HUD_Create(Point2D p);
void HUD_Destroy();
