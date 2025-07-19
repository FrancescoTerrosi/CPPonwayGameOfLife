#ifndef BOARDGUI_H
#define BOARDGUI_H
#include <GL/glut.h>
#include <iostream>

void Display(void);

void Reshape(int w, int h);

void initGame (int argc, char **argv, int population, int timestep);

#endif

