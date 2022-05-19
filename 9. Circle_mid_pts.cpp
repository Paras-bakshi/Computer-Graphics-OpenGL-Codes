
#include "./freeglut-3.2.1/include/GL/freeglut.h"
#include<iostream>
#include<math.h>
using namespace std;

void circle()
{
  glColor3f(1.0, 0.0, 0.0);
  glPointSize(2.0);
  float r = 100;
  float x = 0, y = r;
  float p = 1-r;
  glBegin(GL_POINTS);
  while(x!=y)
    {
      x = x+1;
      if(p<0)
      {
        p = p+ 2*x +3;
      }
      else
      {
        y = y-1;
        p = p+2*x-2*y+5;
      }
  glVertex2i(x, y);
  glVertex2i(y, x);
  glVertex2i(y, -x);
  glVertex2i(x, -y);
  glVertex2i(-x, y);
  glVertex2i(-y, x);
  glVertex2i(-y, -x);
  glVertex2i(-x, -y);

  }
  glEnd();
  glFlush();
}

void init()
{
  glClearColor(1.0,1.0,1.0,0.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 0.0, 0.0);
  glViewport(0, 0, 640, 480);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-250, 250, -250, 250);
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(500, 500);
  glutCreateWindow("Circle_Display");

  init();
  glutDisplayFunc(circle);
  glutMainLoop();
  return 0;
}