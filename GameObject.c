
#include "GameObject.h"
#include "Point2D.h"

#include "Snake.h"
#include "Food.h"
#include "Board.h"
#include "Hud.h"
GameObject objects[MAX_GAME_OBJECTS];

bool GameObject_HandleMessage(Message* msg)
{

}

void* (*a_cf[])(Point2D)={Snake_create,Food_create,Board_create};//,HUD_Create};
GameObject* GameObject_create(Message msg)
{
    msg_Create_Object req = msg.c.create;
    for(int i=0; i<MAX_GAME_OBJECTS;i++)
    {
        if(!GameObject_Exists(i))
        {
            objects[i].ot=req.objectType;
            objects[i].objData=(*a_cf[req.objectType])(req.location);
            return &objects[i];
        }
    }
}

bool GameObject_Exists(int ID)
{
    return objects[ID].ot!=OT_INVALID && objects[ID].objData!=NULL;
}

GameObject* GameObject_get(int ID)
{
    return &objects[ID];
}
