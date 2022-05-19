#include "./freeglut-3.2.1/include/GL/freeglut.h"
#include<iostream>
#include<math.h>
using namespace std;

GLdouble x1, yfirst, x2, y2;
void dda()
{
  GLdouble dx, dy, steps, xinc, yinc, x, y;
  dx = x2-x1;
  dy = y2-yfirst;
  x = x1;
  y = yfirst;
  steps = (abs(dx)>abs(dy))?abs(dx):abs(dy);
  xinc = dx/steps;
  yinc = dy/steps;
  glClear(GL_COLOR_BUFFER_BIT);
  glPointSize(4.0);
  glBegin(GL_POINTS);
    glVertex2d(x, y);
  for(int k = 0; k<steps; k++)
  {
    x = x+xinc;
    y = y+yinc;
    glVertex2d(x, y);
  }
  glEnd();
  glFlush();
}

void init()
{
  glClearColor(1.0,1.0,1.0,0.0);
  glColor3f(1.0, 0.0, 0.0);
  glViewport(0, 0, 640, 480);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, 640, 0, 480);
}

int main(int argc, char **argv)
{
  cout<<"Enter two points for line drawing...\n";
  cout<<"Enter the starting co-ordinate(x1, yfirst): ";
  cin>>x1>>yfirst;
  cout<<"Enter the end co-ordinate(x2, y2): ";
  cin>>x2>>y2;
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowPosition(0, 0);
  glutInitWindowSize(640, 480);
  glutCreateWindow("Line using DDA");

  init();
  glutDisplayFunc(dda);
  glutMainLoop();
  return 0;
}