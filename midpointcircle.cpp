#include <GL/glut.h>
#include <iostream>
using namespace std;
void myinit()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(-500, 500, -500, 500);
	glMatrixMode(GL_PROJECTION);
}

void circle()
{
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(2.0);
	float r = 100;
	float x = 0, y = r;
	float p = 1 - r;
	glBegin(GL_POINTS);
	while (x != y)
	{
		x++;
		if (p < 0) {
			p += 2 * (x + 1) + 1;
		}
		else {
			y--;
			p += 2 * (x + 1) + 1 - 2 * (y - 1);
		}
		glVertex2i(x, y);
		glVertex2i(-x, y);
		glVertex2i(x, -y);
		glVertex2i(-x, -y);
		glVertex2i(y, x);
		glVertex2i(-y, x);
		glVertex2i(y, -x);
		glVertex2i(-y, -x);

	}
	glEnd();
	glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1024, 768);
	glutInitWindowPosition(500, 500);
	glutCreateWindow("Draw OpenGL");
	glutDisplayFunc(circle);
	myinit();
	glutMainLoop();
	return 0;
}