#include "../include/draw.hpp"

// Some global variables
int window_w = 640;
int window_h = 480;
int window_id;
GLfloat angle;
GLfloat fAspect;
KeyState keyarr[NUM_KEYS];

float x_pos = 0;
float y_pos = 0;
float z_pos = 0;

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(window_w, window_h);
  glutInitWindowPosition(0, 0);
  window_id = glutCreateWindow("HUZZAH!");
  glutDisplayFunc(&DrawGLScene);
  glutIdleFunc(&idle);
  glutReshapeFunc(&ReSizeGLScene);
  glutKeyboardFunc(&keyPressed);
	glutKeyboardUpFunc(&keyReleased);
  InitGL();
  glutMainLoop();

	return 0;
}
