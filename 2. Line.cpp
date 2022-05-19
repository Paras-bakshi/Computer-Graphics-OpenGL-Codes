#include "./freeglut-3.2.1/include/GL/freeglut.h"
#include <GL/glut.h>
#include<iostream>
using namespace std;

void init()
{
  glClearColor(1.0,1.0,1.0,0.0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0.0,200.0,0.0,150.0);
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0,0.0,0.0);
  glPointSize(4.0);
  glBegin(GL_LINES);
    glVertex2i(180,15);
    glVertex2i(10,145);
  glEnd();
  glFlush();
}

int main(int argc, char** argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowPosition(50,100);
  glutInitWindowSize(400,300);
  glutCreateWindow("LINE_Display");

  init();
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}