#pragma once

typedef struct
{
    int curScore;
    int hiScore;
} Hud;

Hud* HUD_Create();
void HUD_Destroy();
