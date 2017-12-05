#include "../include/draw.hpp"

/* A general OpenGL initialization function.  Sets all of the initial parameters. */
void InitGL()
{
  GLfloat luzAmbiente[4]={0.2,0.2,0.2,1.0};
	GLfloat luzDifusa[4]={0.7,0.7,0.7,1.0};		        // "cor"
	GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0};     // "brilho"
	GLfloat posicaoLuz[4]={0.0, 50.0, 50.0, 1.0};

	// Capacidade de brilho do material
	GLfloat especularidade[4]={1.0,1.0,1.0,1.0};
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
  //glutFullScreen();

  for(int i = 0; i < NUM_KEYS; ++i)
    keyarr[i] = NOTPUSHED;
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
  gluPerspective(90.0, fAspect, 0.1, 500.0);
}

/* The main drawing function. */
void DrawGLScene()
{
  // Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();
	// Especifica posição do observador e do alvo
  gluLookAt(x_pos, y_pos, z_pos, x_pos + lx, 1.0f, z_pos + lz, 0, 1, 0);
	// Limpa a janela e o depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // glTranslatef(strafe, 0, 0);

  handleMoviment();
  drawSomeShit();

  glFlush();
  // since this is double buffered, swap the buffers to display what just got drawn.
  glutSwapBuffers();
}

/* The function called whenever a key is pressed. */
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
  }
}

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
  }
}

void idle()
{
    glutPostRedisplay();
}
