#include "Collision.h"
#include "Point2D.h"
#include "GameObject.h"
#include "Shape.h"

#define MAX_COLLIDERS 64

#define COLLIDER_INVALID -1
typedef struct Collider
{
    Point2D* p;
    int objectID;
} Collider;

Collider colliderList[MAX_COLLIDERS];

int Collider_Register_Point(int objectID,Point2D* p)
{
    for (size_t i = 0; i < MAX_COLLIDERS; i++)
    {
        if(!Collider_Exists(i))
        {
            colliderList[i].objectID=objectID;
            colliderList[i].p=p;
            return i;
        }
    }
    return COLLIDER_INVALID;
}

void Collider_Deregister(int colliderID)
{
    colliderList[colliderID].objectID=OBJID_INVALID;
    colliderList[colliderID].p=NULL;
}

bool Collider_Exists(int colliderID)
{
    return colliderList[colliderID].p != NULL;
}

void Collisions_detect()
{
    for (size_t i = 0; i < MAX_COLLIDERS; i++)
    {
        if(Collider_Exists(i)){

            for (size_t j = i+1; j < MAX_COLLIDERS; j++)
            {
                if(Collider_Exists(j))
                {
                    if(Point2D_cmp(colliderList[i].p,colliderList[j].p)==0)
                    {
                        msg_Collision a={.other=j};
                        Message_send(MT_COLLISION,colliderList[i].objectID,&a,sizeof(a));
                        msg_Collision b={.other=i};
                        Message_send(MT_COLLISION,colliderList[j].objectID,&b,sizeof(b));
                    }
                }
            }
        }
    }
}