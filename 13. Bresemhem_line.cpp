// C program to demonstrate
// drawing a circle using
// OpenGL
#include<GL/glut.h>
#include<iostream>
using namespace std;
#include<math.h>

GLdouble dx, dy, dx2,dy2;
GLdouble x,y,x1,x2,p0,yfirst,y2;

// function to initialize
void myInit(void)
{
	// making background color black as first
	// 3 arguments all are 0.0
	glClearColor(1.0, 1.0, 1.0, 0.0);

	// making picture color green (in RGB mode), as middle argument is 1.0
	glColor3f(0.0, 1.0, 0.0);

	// breadth of picture boundary is 1 pixel
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);

	// setting window dimension in X- and Y- direction
	gluOrtho2D(0,30,0,30);
}

void brsnhm_line() {
	x = x1;
	y = yfirst;
	dx = x2 - x1;
	dy = y2 - yfirst;
	dx2 = 2 * dx;
	dy2 = 2 * dy;
	p0 = dy2 - dx;

	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	glVertex2i(x, y);

	while (x < x2)
	{
		x = x + 1;
		if (p0 < 0)
		{
			p0 = p0 + dy2;
		}
		else
		{
			y = y + 1;
			p0 = p0 + dy2 - dx2;
		}
		glVertex2i(x, y);
	}

	glEnd();
	glFlush();

}

int main(int argc, char** argv)
{
	

	cout << "Enter the two end points  fo rethe line : \n";
	cout << "Enter the point for x1 and y2";
	cin >> x1 >> yfirst;
	cout << "Enter the point for x2 and y2";
	cin >> x2 >> y2;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	// giving window size in X- and Y- direction
	glutInitWindowSize(1366, 768);
	glutInitWindowPosition(0, 0);

	// Giving name to window
	glutCreateWindow("DDA Line");
	myInit();

	glutDisplayFunc(brsnhm_line);
	glutMainLoop();
}