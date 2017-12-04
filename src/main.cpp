#include "../include/draw.hpp"

// Some global variables
int window_w = 640;
int window_h = 480;
int window_id;
GLfloat angle = 0;
GLfloat fAspect;
KeyState keyarr[NUM_KEYS];

float x_pos = 0.0f;
float y_pos = 1.0f;
float z_pos = 5.0f;

float lx = 0.0f;
float lz = -1.0f;

int cursor_x = 0;
int cursor_y = 0;
int xOrigin = 0;
float deltaAngle = 0;
bool left_screen = false;

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(window_w, window_h);
  glutInitWindowPosition(window_w/2, window_h);
  window_id = glutCreateWindow("HUZZAH!");
  glutDisplayFunc(&DrawGLScene);
  glutIdleFunc(&idle);
  glutReshapeFunc(&ReSizeGLScene);
  glutKeyboardFunc(&keyPressed);
	glutKeyboardUpFunc(&keyReleased);
	glutIgnoreKeyRepeat(1);
	// glutMouseFunc(mouseButton);
	// glutMotionFunc(mouseMove);
	glutPassiveMotionFunc(mousePos);
	glutEntryFunc(mouseOutOfBounds);
  InitGL();
  glutMainLoop();

	return 0;
}
