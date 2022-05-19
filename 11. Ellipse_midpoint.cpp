// https://cs.lmu.edu/~ray/notes/openglexamples/
#include "./freeglut-3.2.1/include/GL/freeglut.h"

// C program to demonstrate
// drawing a circle using
// OpenGL
#include <iostream>
using namespace std;

void ellipse()
{
  glColor3f(1.0,0.0,0.0);
  glPointSize(2.0);
  float rx=70;
  float ry=50;
  float x=0, y=ry;
  float p=((ry*ry)-((rx*rx)*ry)+((rx*rx)/4));
  float dx=2*ry*ry*x;
  float dy=2*rx*rx*y;
  glBegin(GL_POINTS);
  
   while(dx<dy)
    {
      
      if(p<0)
      {
        x=x+1;
        dx=2*(ry*ry)*x;
        p=p+dx+ry*ry;
      }
      else
      {
        x=x+1;
        y=y-1;
        dx=2*ry*ry*x;
        dy=2*rx*rx*y;
        p=p+dx-dy+ry*ry;
      }
      glVertex2i(x,y);
      //glVertex2i(y,x);
      //glVertex2i(y,-x);
      glVertex2i(x,-y);
      glVertex2i(-x,y);
      //glVertex2i(-y,x);
      //glVertex2i(-y,-x);
      glVertex2i(-x,-y);
      
    }
  p=(ry*ry*((x+1/2)*(x+1/2))+rx*rx*((y-1)*(y-1))-rx*rx*ry*ry);
  while(y>0){
      if(p>0)
      {
        y=y-1;
        dy=2*rx*rx*y;
        p=p-dy+rx*rx;
      }
      else
      {
        x=x+1;
        y=y-1;
        dx=2*ry*ry*x;
        dy=2*rx*rx*y;
        p=p+dx-dy+rx*rx;
      }
      glVertex2i(x,y);
      //glVertex2i(y,x);
      //glVertex2i(y,-x);
      glVertex2i(x,-y);
      glVertex2i(-x,y);
      //glVertex2i(-y,x);
      //glVertex2i(-y,-x);
      glVertex2i(-x,-y);
    
  }
  glEnd();
  glFlush();
}

int main(int argc, char**argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowSize(500,500);
  glutInitWindowPosition(100,100);
  glutCreateWindow("Ellipse Display");

  glClearColor(1.0,1.0,1.0,0.0);
  glClear(GL_COLOR_BUFFER_BIT);
  gluOrtho2D(-250,250,-250,250);
  glMatrixMode(GL_PROJECTION);
  glutDisplayFunc(ellipse);
  glutMainLoop();
  return 0;
}