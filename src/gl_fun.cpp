#include "../include/draw.hpp"

void initGameConfig()
{
  for(unsigned int i = 0; i < NUM_KEYS; ++i)
    keyarr[i] = NOTPUSHED;

    // Player initial position
    player.pos.x = 0.0f;
    player.pos.y = 1.0f;
    player.pos.z = 200.0f;

    // Player initial line of sight
    player.ls.x = 0.0f;
    player.ls.z = -1.0f;

    // Camera initial configurations
    xOrigin = 0;
    angle = 0;
    left_screen = false;

    // Clock Timer
    gTimer.minutes = 2;
    gTimer.seconds = 0;

    // Maze
    for(int i = 0; i < NUM_ROW_CUBES; i++)
  		for(int j= 0; j < NUM_COLUMN_CUBES; j++)
      {
        cuboids.push_back(new Cuboid);
        cuboids[j + (i * NUM_ROW_CUBES)]->center.x = i * 20;
        cuboids[j + (i * NUM_ROW_CUBES)]->center.y = 0;
        cuboids[j + (i * NUM_ROW_CUBES)]->center.z = j * 20;

        cuboids[j + (i * NUM_ROW_CUBES)]->height = SIZE_CUBE;
        cuboids[j + (i * NUM_ROW_CUBES)]->length = SIZE_CUBE;
        cuboids[j + (i * NUM_ROW_CUBES)]->depth = SIZE_CUBE;
      }
        // glTranslatef(i * 20.0f, 0.0f, j * 20.0f);
}

/* A general OpenGL initialization function.  Sets all of the initial parameters. */
void InitGL()
{
  GLfloat luzAmbiente[4] = {0.2,0.2,0.2,1.0};
	GLfloat luzDifusa[4] = {0.7,0.7,0.7,1.0};		        // "cor"
	GLfloat luzEspecular[4] = {1.0, 1.0, 1.0, 1.0};     // "brilho"
	GLfloat posicaoLuz[4] = {0.0, 50.0, 50.0, 1.0};

	// Capacidade de brilho do material
	GLfloat especularidade[4] = {1.0,1.0,1.0,1.0};
	GLint especMaterial = 60;

 	// Especifica que a cor de fundo da janela será preta
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// Habilita o modelo de colorização de Gouraud
	glShadeModel(GL_SMOOTH);

	// Define a refletância do material
	glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
	// Define a concentração do brilho
	glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

	// Ativa o uso da luz ambiente
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	// Define os parâmetros da luz de número 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );

	// Habilita a definição da cor do material a partir da cor corrente
	glEnable(GL_COLOR_MATERIAL);
	//Habilita o uso de iluminação
	glEnable(GL_LIGHTING);
	// Habilita a luz de número 0
	glEnable(GL_LIGHT0);
	// Habilita o depth-buffering
	glEnable(GL_DEPTH_TEST);

  glutSetCursor(GLUT_CURSOR_NONE);
  glutWarpPointer(window_w/2, window_h/2);
}

/* The function called when our window is resized (which shouldn't happen, because we're fullscreen) */
void ReSizeGLScene(int Width, int Height)
{
  // Especifica o tamanho da viewport
  glViewport(0, 0, Width, Height);

	// Calcula a correção de aspecto
	fAspect = (GLfloat)Width/(GLfloat)Height;

  // Especifica sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);

  // Inicializa sistema de coordenadas de projeção
	glLoadIdentity();

	// Especifica a projeção perspectiva
  gluPerspective(45.0, fAspect, 0.1, 500.0);
}

void DrawGLScene()
{
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  handleMoviment();
  Point current;
  current.x = player.pos.x + tmpX;
	current.y = player.pos.y;
	current.z = player.pos.z + tmpZ;
  collisionX = false;
  collisionY = false;
  collisionZ = false;

  for(unsigned int i = 0; i < cuboids.size(); ++i)
  {
    theresCollision(cuboids[i], current);
  }

  if(!collisionX)
  {
    player.pos.x += tmpX;
  }

  if(!collisionZ)
  {
    player.pos.z += tmpZ;
  }

  gluLookAt(player.pos.x, player.pos.y, player.pos.z,
            player.pos.x + player.ls.x, player.pos.y, player.pos.z + player.ls.z,
            0, 1, 0);

  // Draw enviroment
  // drawGround();
  // drawWalls();
  drawMaze();

  // Game functions


  printTimer();
  // normalHeight();

  // glFlush();
  glutSwapBuffers();
}

// The function called whenever a key is pressed.
void keyPressed(unsigned char key, int x, int y)
{
  switch (key)
  {
    case ESC:
    {
      glutDestroyWindow(window_id);
      exit(EXIT_SUCCESS);
    }
    case 'w':
    {
      keyarr[int('w')] = PUSHED;
      break;
    }
    case 'a':
    {
      keyarr[int('a')] = PUSHED;
      break;
    }
    case 's':
    {
      keyarr[int('s')] = PUSHED;
      break;
    }
    case 'd':
    {
      keyarr[int('d')] = PUSHED;
      break;
    }

    case 'c':
    {
      keyarr[int('c')] = PUSHED;
      break;
    }

    // Space bar
    case 32:
    {
      keyarr[32] = PUSHED;
      break;
    }
  }
}

// The function called whenever a key is released.
void keyReleased(unsigned char key, int x, int y)
{
  switch (key)
  {
    case 'w':
    {
      keyarr[int('w')] = NOTPUSHED;
      break;
    }
    case 'a':
    {
      keyarr[int('a')] = NOTPUSHED;
      break;
    }
    case 's':
    {
      keyarr[int('s')] = NOTPUSHED;
      break;
    }
    case 'd':
    {
      keyarr[int('d')] = NOTPUSHED;
      break;
    }
    case 'c':
    {
      keyarr[int('c')] = NOTPUSHED;
      break;
    }
    case 32:
    {
      keyarr[32] = NOTPUSHED;
      break;
    }
  }
}

void idle()
{
    glutPostRedisplay();
}
