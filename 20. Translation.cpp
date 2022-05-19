#include <GL/gl.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>
void init(){
glClearColor(1,1,1,1.0);
glPointSize(2.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-500, 500.0,-500.0,500.0);
}
void makeTriangle(float x1,float y1,float x2,float y2,float x3, float y3){
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0,0.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(x1, y1);
glVertex2f(x2, y2);
glVertex2f(x3, y3);

}
void translate(float x1,float y1,float x2,float y2,float x3,float y3){
glClear(GL_COLOR_BUFFER_BIT);
x1=x1+150;
x2=x2+150;
x3=x3+150;
y1=y1+150;
y2=y2+150;
y3=y3+150;
makeTriangle(x1,y1,x2,y2,x3,
y3);glEnd();glColor3f(0,0.0,0.0);
glBegin(GL_LINES);glVertex2f(-
500,0);glVertex2f(500,0);
glBegin(GL_LINES);glVertex2f(0,
-500);glVertex2f(0,500);glEnd();
glFlush();
}void
display(){
makeTriangle(0,0,60.0,140.0,110.0,0.0);
translate(0,0,60.0,140.0,110.0,0.0);
}
int main(int argc,char** argv){
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(100,100);
glutInitWindowSize(800,600);
glutCreateWindow("Translation");
init();
glutDisplayFunc(display);
glutMainLoop();
}