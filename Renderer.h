#pragma once

void Renderer_initialize();
void Renderer_close();
void Renderer_refreshScreen();
int Renderer_scanInput(); 
void Renderer_nextFrame();
void Renderer_waitUntilNextFrame();
