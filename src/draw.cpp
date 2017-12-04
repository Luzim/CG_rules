#include "../include/draw.hpp"

void drawSomeShit()
{
	// Draw ground
	glColor3f(0.9f, 0.9f, 0.9f);
	glBegin(GL_QUADS);
		glVertex3f(-100.0f, 0.0f, -100.0f);
		glVertex3f(-100.0f, 0.0f,  100.0f);
		glVertex3f( 100.0f, 0.0f,  100.0f);
		glVertex3f( 100.0f, 0.0f, -100.0f);
	glEnd();

        // Draw 36 SnowMen
	for(int i = -3; i < 3; i++)
		for(int j= -3; j < 3; j++)
    {
			glPushMatrix();
			   glTranslatef(i * 10.0f, 0.0f, j * 10.0f);
			   drawSnowMan();
			glPopMatrix();
		}
}

void drawSnowMan()
{
	glColor3f(1.0f, 1.0f, 1.0f);

// Draw Body
	glTranslatef(0.0f ,0.75f, 0.0f);
	glutSolidSphere(0.75f,20,20);

// Draw Head
	glTranslatef(0.0f, 1.0f, 0.0f);
	glutSolidSphere(0.25f,20,20);

// Draw Eyes
	glPushMatrix();
	glColor3f(0.0f,0.0f,0.0f);
	glTranslatef(0.05f, 0.10f, 0.18f);
	glutSolidSphere(0.05f,10,10);
	glTranslatef(-0.1f, 0.0f, 0.0f);
	glutSolidSphere(0.05f,10,10);
	glPopMatrix();

// Draw Nose
	glColor3f(1.0f, 0.5f , 0.5f);
	glutSolidCone(0.08f,0.5f,10,2);
}

void handleMoviment()
{
	// if(angle <= -2*M_PI || angle >= 2*M_PI)
	// 	angle = 0;

	if(keyarr['w'])
	{
		x_pos += lx * SPEED;
		z_pos += lz * SPEED;
	}
  if(keyarr['a'])
	{
		x_pos -= -1 * lz * SPEED;
		z_pos -= lx * SPEED;
		// angle -= 0.005f;
		// lx = sin(angle)/3;
		// lz = -cos(angle)/3;
	}
  if(keyarr['s'])
	{
		x_pos -= lx * SPEED;
		z_pos -= lz * SPEED;

	}
  if(keyarr['d'])
	{
		x_pos += -1 * (lz * SPEED);
		z_pos += lx * SPEED;
	// 	angle += 0.005f;
	// 	lx = sin(angle)/3;
	// 	lz = -cos(angle)/3;
	}

	if(keyarr['c'])
	{
	glTranslatef(0.0f, 0.5f, 0.0f);
	// 	angle += 0.005f;
	// 	lx = sin(angle)/3;
	// 	lz = -cos(angle)/3;
	}

}

void mouseButton(int button, int state, int x, int y)
{
	// // only start motion if the left button is pressed
	// if (button == GLUT_LEFT_BUTTON) {
  //
	// 	// when the button is released
	// 	if (state == GLUT_UP) {
	// 		angle += deltaAngle;
	// 		xOrigin = -1;
	// 	}
	// 	else  {// state = GLUT_DOWN
	// 		xOrigin = x;
	// 	}
	// }
}

void mouseMove(int x, int y)
{
	// // this will only be true when the left button is down
	// if (xOrigin >= 0)
	// {
	// 	// update deltaAngle
	// 	deltaAngle = (x - xOrigin) * 0.001f;
  //
	// 	// update camera's direction
	// 	lx = sin(angle + deltaAngle);
	// 	lz = -cos(angle + deltaAngle);
	// }
}

void mousePos(int x, int y)
{
	if(left_screen)
	{
		xOrigin = x;
		left_screen = false;
	}
	deltaAngle += (x - xOrigin) * MOUSE_SENSITIVITY;


	// update camera's direction
	lx = sin(deltaAngle);
	lz = -cos(deltaAngle);

	xOrigin = x;
}

void mouseOutOfBounds(int state)
{
	if(state == GLUT_LEFT)
	{
  	glutWarpPointer(window_w/2, window_h/2);
		left_screen = true;
	}
}
