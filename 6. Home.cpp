#include "./freeglut-3.2.1/include/GL/freeglut.h"
#include <GL/glut.h>
#include<iostream>
using namespace std;

void init()
{
  glClearColor(1.0,1.0,1.0,0.0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 0.0, 0.0);
  glPointSize(4.0);
  glBegin(GL_LINE_STRIP);
    glVertex2i(1, 90);
    glVertex2i(90, 90);
    glVertex2i(90, 9);
    glVertex2i(1, 9);
  glBegin(GL_LINE_STRIP);
    glVertex2i(1, 90);
    glVertex2i(45, 120);
    glVertex2i(90,90);
  glEnd();
  glBegin(GL_LINE_STRIP);
    glVertex2i(30, 9);
    glVertex2i(30, 50);
    glVertex2i(50,50);
    glVertex2i(50,9);
  glEnd();
  glBegin(GL_LINE_STRIP);
    glVertex2i(55, 114);
    glVertex2i(55, 130);
    glVertex2i(65,140);
    glVertex2i(65,106);

  glEnd();
  glFlush();
}

int main(int argc, char** argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowPosition(50,100);
  glutInitWindowSize(400,300);
  glutCreateWindow("HOME");

  init();
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}