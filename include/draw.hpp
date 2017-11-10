#ifndef _DRAW_HPP_
#define _DRAW_HPP_

#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <limits>

#include <cstdio>
#include <cstdlib>
#include <unistd.h>

// OpenGL Graphic Library Utility Tools
#include <GL/glut.h>

// Some defines
#define ESCAPE 27

// Some global variables
extern int window_w;
extern int window_h;
extern int window_id;

// OpenGL functions
void InitGL(int Width, int Height);
void ReSizeGLScene(int Width, int Height);
void DrawGLScene();
void keyPressed(unsigned char key, int x, int y);

using namespace std;

#endif
