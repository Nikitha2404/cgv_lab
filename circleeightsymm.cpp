#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>
int degree, x,y,r = 100, xc =300, yc = 300;
float theta;
void myInit(void)
{
	glClearColor(2.0, 2.0, 2.0, 4.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
void eight_way_sym(float x, float y)
{
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glVertex2f(y, x);
	glVertex2f(-x, y);
	glVertex2f(-y, x);
	glVertex2f(-x, -y);
	glVertex2f(-y, -x);
	glVertex2f(x, -y);
	glVertex2f(y, -x);
	glEnd();
	glFlush();
}
void displaytrigeight()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	for (theta = 0; theta < 45; theta++)
	{
		x = xc + r * cos(theta);
		y = yc + r * sin(theta);
		eight_way_sym(x, y);
	}
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Circle");
	glutDisplayFunc(displaytrigeight);
	myInit();
	glutMainLoop();
}