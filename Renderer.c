
#include <ncurses.h>

#include "Message.h"

void Renderer_initialize()
{
    initscr();
    curs_set(0);
    keypad(stdscr, TRUE);
    cbreak();
    noecho();
}
void Renderer_close()
{
    endwin();
}
void Renderer_refreshScreen()
{
    refresh();
}

int glob_c=0;
int Renderer_scanInput()
{
    int c=0;
    if(glob_c!=ERR)
    {
        Message_send(MSGTGT_GAME_ENGINE,&glob_c,1);
    }
    glob_c=0;
    return c;
}
void Renderer_nextFrame()
{
    clear();
}
void Renderer_waitUntilNextFrame()
{
    halfdelay(2);
    glob_c=getch();
}
