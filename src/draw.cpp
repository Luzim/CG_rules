#include "../include/draw.hpp"

void drawMaze()
{
	for(unsigned int i = 0; i < cuboids.size(); i++)
		drawCube(i%2, cuboids[i]);


	// glTranslatef(0.0f, - SIZE_CUBE - 1.0f, 0.0f);
	// for(int i = -5; i < 5; i++)
	// 	for(int j= -5; j < 5; j++)
  //   {
	// 		glPushMatrix();
	// 		   glTranslatef(i * 10.0f, 0.0f, j * 10.0f);
	// 			 j%2 ? drawCube(i % 2) : drawCube((i + 1) % 2);
	// 		glPopMatrix();
	// 	}
}

void drawGround()
{
	glColor3f(0.2f, 0.9f, 0.2f);
	glBegin(GL_QUADS);
		glVertex3f(-100.0f, - SIZE_CUBE - 1.0f, -100.0f);
		glVertex3f(-100.0f, - SIZE_CUBE - 1.0f,  100.0f);
		glVertex3f( 100.0f, - SIZE_CUBE - 1.0f,  100.0f);
		glVertex3f( 100.0f, - SIZE_CUBE - 1.0f, -100.0f);
	glEnd();
}

void drawCube(int color, Cuboid* cuboid)
{
	if(color)
		glColor3f(0.647059f, 0.164706f, 0.164706f);
	else
		glColor3f(1.0f, 1.0f, 1.0f);

	glPushMatrix();
		glTranslatef(cuboid->center.x, cuboid->center.y, cuboid->center.z);
		glScalef(cuboid->length, cuboid->height, cuboid->depth);
		glutSolidCube(1);
	glPopMatrix();
}

void drawWalls()
{
	glColor3f(1.0f, 0.5f , 0.5f);
	glPushMatrix();
		glTranslatef(-45.0f,4.0f,-5.0f);
		glScalef(1.0f,SIZE_CUBE,SIZE_CUBE*5);
		glutSolidCube(SIZE_CUBE/4);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(35.0f,4.0f,-5.0f);
		glScalef(1.0f,SIZE_CUBE,SIZE_CUBE*5);
		glutSolidCube(SIZE_CUBE/4);
	glPopMatrix();
}

void wallFront()
{
	glColor3f(1.0f, 0.5f , 0.5f);
	glPushMatrix();
		glTranslatef(-45.0f,4.0f,-5.0f);
		glScalef(1.0f,SIZE_CUBE,SIZE_CUBE*5);
		glRotatef(-90,0.,1.,0.);
		glutSolidCube(SIZE_CUBE/4);
	glPopMatrix();
}

void handleMoviment(Cuboid* cuboid)
{
	Point current;
	float tmpX = 0;
	float tmpZ = 0;

	if(keyarr['w'])
	{
		tmpX = player.ls.x * SPEED;
		tmpZ = player.ls.z * SPEED;
		// player.pos.x += player.ls.x * SPEED;
		// player.pos.z += player.ls.z * SPEED;
	}
  if(keyarr['a'])
	{
		// player.pos.x -= -1 * player.ls.z * SPEED;
		// player.pos.z -= player.ls.x * SPEED;
	}
  if(keyarr['s'])
	{
		tmpX = -1 * player.ls.x * SPEED;
		tmpZ = -1 * player.ls.z * SPEED;
		// player.pos.x -= player.ls.x * SPEED;
		// player.pos.z -= player.ls.z * SPEED;

	}
  if(keyarr['d'])
	{
		// player.pos.x += -1 * (player.ls.z * SPEED);
		// player.pos.z += player.ls.x * SPEED;
	}

	current.x = player.pos.x + tmpX;
	current.y = player.pos.y;
	current.z = player.pos.z + tmpZ;

	if(!theresCollision(cuboid, current))
	{
		player.pos.x += tmpX;
		player.pos.z += tmpZ;
	}

	if(keyarr['c'])
	{
		printCubeZeroPos();
		// if(player.pos.y > 0.4)
		// 	player.pos.y -= 0.1;
	}

	if(keyarr[32])
	{
		printPlayerPos();
		// if(player.pos.y < 2.0)
		// 	player.pos.y += 0.01;
	}
}

void mousePos(int x, int y)
{
	if(left_screen)
	{
		xOrigin = x;
		left_screen = false;
	}
	angle += (x - xOrigin) * MOUSE_SENSITIVITY;


	// update camera's direction
	player.ls.x = sin(angle);
	player.ls.z = -cos(angle);

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

void printTimer()
{
	char current_time[20];
	sprintf(current_time, "%.0f:%.0f", gTimer.minutes, gTimer.seconds);

	//set the position of the text in the window using the x, y and z coordinates
	glRasterPos3f(player.pos.x + player.ls.x, 0.9 + player.pos.y, player.pos.z + player.ls.z);

	//get the length of the string to display
	int len = (int) strlen(current_time);

	//loop to display character by character
	for (int i = 0; i < len; i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, current_time[i]);
}

void Timer(int value)
{
	glutTimerFunc(1000, Timer, 0);

	if(gTimer.seconds <= 0)
	{
		gTimer.seconds = 59;
		gTimer.minutes--;
	}
	else
		gTimer.seconds--;
}

void normalHeight()
{
	if(player.pos.y < 1 && !keyarr['c'])
		player.pos.y += 0.1;

	if(player.pos.y > 1 && !keyarr[32])
		player.pos.y -= 0.02;
}

bool theresCollision(Cuboid* cuboid, Point player)
{
	if( ((cuboid->center.x - cuboid->length) <= player.x && player.x <= (cuboid->center.x + cuboid->length)) &&
		  ((cuboid->center.y - cuboid->height) <= player.y && player.y <= (cuboid->center.y + cuboid->height)) &&
		  ((cuboid->center.z - cuboid->depth)  <= player.z && player.z <= (cuboid->center.z + cuboid->depth)) )
			{
				printPlayerPos();
				return true;
			}

	return false;
}

void printPlayerPos()
{
	printf("Player (%2.2f, %2.2f, %2.2f)\n", player.pos.x, player.pos.y, player.pos.z);
}

void printCubeZeroPos()
{
	printf("Cuboid 0: (%2.2f, %2.2f, %2.2f)\n", cuboids[0]->center.x - cuboids[0]->length,
																							cuboids[0]->center.y - cuboids[0]->height,
																							cuboids[0]->center.z - cuboids[0]->depth);
}
