#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>

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

void scaling(float x1, float y1, float x2, float y2, float x3, float y3) {
  float new_x1 = x1 * 0.60;
  float new_y1 = y1 * 0.5;
  float new_x2 = x2 * 0.60;
  float new_y2 = y2  * 0.5;
  float new_x3 = x3  * 0.60;
  float new_y3 = y3  * 0.5;
  makeTriangle(new_x1, new_y1, new_x2, new_y2, new_x3, new_y3);
  glEnd();
  glFlush();
}
void display() {
  makeTriangle(150, 150, 180.0, 220.0, 250.0, 100.0);
  scaling(150, 150, 180.0, 220.0, 250.0, 100.0);
}
int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(400, 400);
  glutCreateWindow("Scaling");
  init();
  glutDisplayFunc(display);
  glutMainLoop();
}
