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

typedef struct
{
    bool quit;
} Game_Message;

#define MSGTGT_GAME_ENGINE -1
int main(int argc, char** argv)
{
    game_Initialize();
    bool quit=false;
    while (true)
    {
        Message* msg;
        while((msg = Message_receive())!=NULL)
        {
            game_HandleMessage(msg);
            if(!msg->handled)
            {
                if(msg->targetID==MSGTGT_GAME_ENGINE)
                {
                    Game_Message* msgdata=(Game_Message*)(msg->data);
                    if(msgdata->quit)
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

Object_Create_req initialize_req[]=
{
{.objectType=OT_SNAKE,.location={.x=10,.y=10}}
//{.objectType=OT_SNAKE,.x=10,.y=10},
//{.objectType=OT_SNAKE,.x=10,.y=10},
};
const int OBJ_INITIALIZE_COUNT=sizeof(initialize_req)/sizeof(Object_Create_req);


void game_Initialize()
{
    Renderer_initialize();
    srand(time(NULL));
    for(int i=0;i<OBJ_INITIALIZE_COUNT;i++)
    {
        GameObject_create(initialize_req[i]);
    }
//    Snake* snake = Snake_create((Point2D){.x=5,.y=10});
//    Board* board = Board_create((Point2D){.x=40,.y=20});
//    Point2D p={.x=rand()%20,.y=rand()%20};
//    Food* food=Food_create(p);
//    Hud* hud=HUD_Create(p);
}

bool game_HandleMessage(Message* msg)
{
    return GameObject_HandleMessage(msg);
}

ticUpdateFunction a_tuf[]={Snake_tickUpdate};
void game_AdvanceTick()
{
    for(int i=0;i<MAX_GAME_OBJECTS;i++)
    {
        if(GameObject_Exists(i))
        {
            GameObject* go = GameObject_get(i);
            a_tuf[go->ot](go->objData);
        }
    }
}

ticUpdateFunction a_rf[]={Render_Snake};
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
