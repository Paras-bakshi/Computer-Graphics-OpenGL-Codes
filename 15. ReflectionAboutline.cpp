#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
using namespace std;
void init() {
  glClearColor(1, 1, 1, 1.0);
  glPointSize(2.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-500, 500.0, -500.0, 500.0);
}
void makeTriangle(float x1, float y1, float x2, float y2, float x3, float y3) {
      glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 0.0, 1.0);
  glBegin(GL_TRIANGLES);
  glVertex2f(x1, y1);
  glVertex2f(x2, y2);
  glVertex2f(x3, y3);
}
void reflection(float x1, float y1, float x2, float y2, float x3, float y3) {
  float new_x1 = y1 - 2;
  float new_y1 = x1 + 2;
  float new_x2 = y2 - 2;
  float new_y2 = x2 + 2;
  float new_x3 = y3 - 2;
  float new_y3 = x3 + 2;
  makeTriangle(new_x1, new_y1, new_x3, new_y3, new_x2, new_y2);
}
void display() {
  makeTriangle(-100, -200, 40, 42, 300, -100);
  reflection(-100, -200, 40, 42, 300, -100);
  glEnd();
  glFlush();
}
int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(800, 600);
  glutCreateWindow("Reflection");
  init();
  glutDisplayFunc(display);
  glutMainLoop();
}