
#include "./freeglut-3.2.1/include/GL/freeglut.h"
#include<iostream>
#include<math.h>
using namespace std;

void circle()
{
  glColor3f(1.0, 0.0, 0.0);
  glPointSize(2.0);
  float r = 70;
  float x = 0, y = r;
  float p = 3-2*r;
  glBegin(GL_POINTS);
  while(x!=y)
    {
      x = x+1;
      if(p<0)
      {
        p = p+ 4*x +6;
      }
      else
      {
        y = y-1;
        p = p+4*x-4*y+10;
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

void linee()
{
  //glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0,0.0,0.0);
  glPointSize(4.0);
  glBegin(GL_LINES);
    glVertex2i(0,-70);
    glVertex2i(0,-150);
  glEnd();
  glFlush();
}

void lineee()
{
  //glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0,0.0,0.0);
  glPointSize(4.0);
  glBegin(GL_LINES);
    glVertex2i(0,-150);
    glVertex2i(-50,-230);
  glEnd();
  glFlush();
}
void lineeee()
{
  //glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0,0.0,0.0);
  glPointSize(4.0);
  glBegin(GL_LINES);
    glVertex2i(0,-150);
    glVertex2i(50,-230);
  glEnd();
  glFlush();
}

void display()
{
  circle();
  linee();
  lineee();
  lineeee();
  }

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(500, 500);
  glutCreateWindow("Circle Display with Breshenham");

  init();
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}