#include "../include/draw.hpp"

void drawSomeShit()
{
	// glBegin(GL_QUADS);
  //
	// glEnd();
	// glFlush();

}

void handleMoviment()
{
	if(keyarr['w'])
    z_pos += 0.08;
  if(keyarr['a'])
    x_pos += 0.08;
  if(keyarr['s'])
    z_pos -= 0.08;
  if(keyarr['d'])
		x_pos -= 0.08;
}
