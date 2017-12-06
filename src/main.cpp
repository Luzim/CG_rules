#include "../include/draw.hpp"

// Some global variables
int window_w = 1024;
int window_h = 720;
int window_id;
GLfloat fAspect;
KeyState keyarr[NUM_KEYS];

gameTimer gTimer;
Player player;
vector<Cuboid*> cuboids;

bool left_screen;
int xOrigin;
float angle;

int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	// Windows configurations functions
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(window_w, window_h);
  glutInitWindowPosition(50, 0);
  window_id = glutCreateWindow("HUZZAH!");

	// Display Functions
	glutDisplayFunc(&DrawGLScene);
  glutIdleFunc(&idle);
  glutReshapeFunc(&ReSizeGLScene);

	// Keyboard Functions
  glutKeyboardFunc(&keyPressed);
	glutKeyboardUpFunc(&keyReleased);
	glutIgnoreKeyRepeat(1);

	// Mouse Functions
	glutPassiveMotionFunc(mousePos);
	glutEntryFunc(mouseOutOfBounds);

	// Program inital setup configurations
	initGameConfig();
	InitGL();
	Timer(0);

  glutMainLoop();
	return 0;
}
