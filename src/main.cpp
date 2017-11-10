#include "../include/draw.hpp"

// Some global variables
int window_w = 640;
int window_h = 480;
int window_id;

int main(int argc, char** argv)
{

	/* Initialize GLUT state - glut will take any command line arguments that pertain to it or
		 X Windows - look at its documentation at http://reality.sgi.com/mjk/spec3/spec3.html */
	glutInit(&argc, argv);

	/* Select type of Display mode:
     Double buffer
     RGBA color
     Alpha components supported
     Depth buffer */
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);

	/* get a 640 x 480 window */
  glutInitWindowSize(window_w, window_h);

	/* the window starts at the upper left corner of the screen */
  glutInitWindowPosition(0, 0);

	/* Open a window */
  window_id = glutCreateWindow("Oh, yeah!");

	/* Register the function to do all our OpenGL drawing. */
  glutDisplayFunc(&DrawGLScene);

  /* Go fullscreen.  This is as soon as possible. */
  //glutFullScreen();

  /* Even if there are no events, redraw our gl scene. */
  glutIdleFunc(&DrawGLScene);

  /* Register the function called when our window is resized. */
  glutReshapeFunc(&ReSizeGLScene);

  /* Register the function called when the keyboard is pressed. */
  glutKeyboardFunc(&keyPressed);

  /* Initialize our window. */
  InitGL(640, 480);

  /* Start Event Processing Engine */
  glutMainLoop();

	return 0;
}
