#include "Hud.h"
#include "Point2D.h"
Hud globhud;

Hud* HUD_Create(Point2D p)
{
    globhud.curScore=0;
    globhud.hiScore=0;
    return &globhud;
}

void HUD_Destroy()
{
    //Does nothing, HUD is currently statically allocated
}

void HUD_updateScore(int score)
{
    if(score<globhud.curScore&&globhud.curScore>globhud.hiScore)
    {
        globhud.hiScore=globhud.curScore;
    }

    globhud.curScore=score;
}