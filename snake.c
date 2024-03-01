#define EXIT_KEY 'q'
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#include "Snake.h"
#include "Renderer.h"
#include "Render_objects.h"
#include "Food.h"
#include "Board.h"
#include "Message.h"
#include "GameObject.h"
#include <stdio.h>

Point2D ktov(int key);
int snake_getScore();

void game_Initialize();
bool game_HandleMessage(Message* msg);
void game_AdvanceTick();
void game_RenderScreen();

GameObject* player;
int main(int argc, char** argv)
{
    game_Initialize();
    bool quit=false;
    while (true)
    {

        Renderer_scanInput();

        Message* msg;
        while((msg = Message_receive())!=NULL)
        {
            game_HandleMessage(msg);
            if(!msg->handled)
            {
                if(msg->targetID==MSGTGT_GAME_ENGINE)
                {
                    msg_GameMessage* gameMessage=(msg_GameMessage*)&(msg->c.gameMessage);
                    if(gameMessage->quit)
                    quit=true;
                    msg->handled==true;
                }

                printf("Warning: Message unhandled");
                msg->handled==true;
            }
        }
        game_AdvanceTick();
        game_RenderScreen();

        Renderer_waitUntilNextFrame();

    }while(!quit)
    return 0;
}


/*
    int c;
    bool exit=false;

    do
    {
        //Input
        c=Renderer_scanInput();

        //Game Logic
        Snake_setVelocity(ktov(c));
        HUD_updateScore(snake_getScore());
        Snake_tickUpdate();

        if(Food_handleCollision(snake,food))
        {
            Snake_extend();
            Point2D p={.x=rand()%20,.y=rand()%20};
            Food_destroy(food);
            food=Food_create(p);

        }
        if(Board_SnakeCollision(board,snake))
        {
            Snake_delete(snake);
            Snake_create(rand()%20,rand()%20);
            Snake_setVelocity((Point2D){.x=0,.y=0});

        }

        //Rendering
        Render_Snake(snake);
        Render_Food(food);
        Render_Board(board);
        Render_HUD(hud);

        if(c==EXIT_KEY) exit=true;

    }while(!exit);

    Snake_delete(snake);
    Food_destroy(food);
    Renderer_close();
    return 0;

*/


Vector2D ktov(int c)
{
    Vector2D ret;
    switch (c)
    {
    case KEY_UP:
        ret.x=0;
        ret.y=1;
        break;

    case KEY_DOWN:
        ret.x=0;
        ret.y=-1;
        break;

    case KEY_LEFT:
        ret.x=-1;
        ret.y=0;
        break;

    case KEY_RIGHT:
        ret.x=1;
        ret.y=0;
        break;

    default:
        ret=Point2D_invalid;
        break;
    }
    return ret;
}
/*
int snake_getScore()
{
    return Snake_getLength();
}
*/

Message initialize_req[]=
{
{.c.create={.objectType=OT_SNAKE,.location={.x=10,.y=10}}},
{.c.create={.objectType=OT_FOOD, .location={.x=20,.y=10}}},
{.c.create={.objectType=OT_BOARD, .location={.x=40,.y=20}}},
};
const int OBJ_INITIALIZE_COUNT=sizeof(initialize_req)/sizeof(Message);

//initializes
void game_Initialize()
{
    Renderer_initialize();
    srand(time(NULL));
    for(int i=0;i<OBJ_INITIALIZE_COUNT;i++)
    {
        GameObject_create(initialize_req[i]);
    }
//    Hud* hud=HUD_Create(p);
}

bool game_HandleMessage(Message* msg)
{
    return GameObject_HandleMessage(msg);
}

ticUpdateFunction a_tuf[]={Snake_tickUpdate,NULL,NULL};
void game_AdvanceTick()
{
    for(int i=0;i<MAX_GAME_OBJECTS;i++)
    {
        if(GameObject_Exists(i))
        {
            GameObject* go = GameObject_get(i);
            if(a_tuf[go->ot])
            {
                a_tuf[go->ot](go->objData);
            }
        }
    }
}

rendererFunction a_rf[]={Render_Snake,Render_Food,Render_Board};
void game_RenderScreen()
{
    Renderer_nextFrame();
    for(int i=0;i<MAX_GAME_OBJECTS;i++)
    {
        if(GameObject_Exists(i))
        {
            GameObject* go = GameObject_get(i);
            a_rf[go->ot](go->objData);
        }
    }
}
