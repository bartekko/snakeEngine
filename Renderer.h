#pragma once

#include <ncurses.h>

#define Renderer_initialize()    initscr();curs_set(0);
#define Renderer_close()         endwin()
#define Renderer_refreshScreen() 