#pragma once

#include <ncurses.h>

#define Renderer_initialize()    initscr()
#define Renderer_close()         endwin()
#define Renderer_refreshScreen() 