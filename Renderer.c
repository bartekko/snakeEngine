#include <ncurses.h>

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