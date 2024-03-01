#pragma once

void Renderer_initialize();
void Renderer_close();
void Renderer_refreshScreen();
int Input_scan();
void Renderer_nextFrame();
void Input_waitUntilNextFrame();
