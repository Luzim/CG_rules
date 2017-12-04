#ifndef _DRAW_HPP_
#define _DRAW_HPP_

#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <limits>

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <unistd.h>

// OpenGL Graphic Library Utility Tools
#include <GL/glut.h>

#define NUM_KEYS 127
#define ESC 27
#define SPEED 0.05
#define MOUSE_SENSITIVITY 0.01f

enum KeyState
{
	NOTPUSHED,
	PUSHED
};

// Some global variables
extern int window_w;
extern int window_h;
extern int window_id;
extern GLfloat angle;
extern GLfloat fAspect;
extern KeyState keyarr[NUM_KEYS];

extern float x_pos;
extern float y_pos;
extern float z_pos;

extern float lx;
extern float lz;

extern int cursor_x;
extern int cursor_y;
extern int xOrigin;
extern float deltaAngle;
extern bool left_screen;


using namespace std;

// OpenGL functions
void InitGL();
void ReSizeGLScene(int Width, int Height);
void DrawGLScene();
void keyPressed(unsigned char key, int x, int y);
void keyReleased(unsigned char key, int x, int y);
void mouseButton(int button, int state, int x, int y);
void mouseOutOfBounds(int state);
void mouseMove(int x, int y);
void mousePos(int x, int y);
void handleMoviment();
void idle();

// Drawing functions
void drawSomeShit();
void drawSnowMan();

#endif
