#ifndef _DRAW_HPP_
#define _DRAW_HPP_

#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <limits>
#include <vector>

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <unistd.h>

// OpenGL Graphic Library Utility Tools
#include <GL/glut.h>
#define SIZE_CUBE 10
#define NUM_ROW_CUBES 10
#define NUM_COLUMN_CUBES 10
#define CORRIDOR_WIDTH 20
#define NUM_KEYS 127
#define ESC 27
#define SPEED 0.02
#define MOUSE_SENSITIVITY 0.001f
#define COLLISION_OFFSET 0.2

typedef struct Point
{
	float x;
	float y;
	float z;
} Point;

typedef struct Cuboid
{
	Point center;

	float height;
	float length;
	float depth;
}Cuboid;

typedef struct Player
{
	// Player position
	Point pos;

	// Line of sight
	Point ls;
} Player;

typedef struct gameTimer
{
	float minutes;
	float seconds;
}gameTimer;

enum KeyState
{
	NOTPUSHED,
	PUSHED
};

using namespace std;

// Some global variables
extern int window_w;
extern int window_h;
extern int window_id;
extern GLfloat fAspect;
extern KeyState keyarr[NUM_KEYS];

// Game variables
extern gameTimer gTimer;
extern Player player;
extern vector<Cuboid*> cuboids;
extern float tmpX;
extern float tmpZ;
extern bool collisionX;
extern bool collisionY;
extern bool collisionZ;

// Camera variables
extern int xOrigin;
extern float angle;
extern bool left_screen;

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
void idle();

// Game functions
void initGameConfig();
void handleMoviment();
void theresCollision(Cuboid* cuboid, Point player);
void collX(Cuboid* cuboid, Point player);
void collY(Cuboid* cuboid, Point player);
void collZ(Cuboid* cuboid, Point player);

// Drawing functions
void drawGround();
void drawWalls();
void drawCube(int color, Cuboid* cuboid);
void drawMaze();
void Timer(int value);
void printTimer();
void normalHeight();

// DEBUG FROM theresCollision
void printPlayerPos();
void printCubeZeroPos();

#endif
