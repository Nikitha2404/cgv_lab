#include<stdlib.h>
#include<GL/glut.h>
float v[3][2] = { {-25,-25},{0,25},{25,-25} };
void myinit()
{
	glMatrixMode(GL_PROJECTION_MATRIX);
	glLoadIdentity();
	gluOrtho2D(-50, 50, -50, 50);
	glMatrixMode(GL_MODELVIEW);
}
void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_LOOP);
	glVertex2fv(v[0]);
	glVertex2fv(v[1]);
	glVertex2fv(v[2]);
	glEnd();
	float p[2] = { 0,0 };
	int i, n = 7000, j;
	glPointSize(2);
	for (i = 0; i < n; i++)
	{
		j = rand() % 3;
		if (j == 0)
			glColor3f(1, 0, 0);
		else if (j == 1)
			glColor3f(0, 1, 0);
		else
			glColor3f(0, 0, 1);
		p[0] = (p[0] + v[j][0]) / 2;
		p[1] = (p[1] + v[j][1]) / 2;
		glBegin(GL_POINTS);
		glVertex2fv(p);
		glEnd();
		glFlush();
	}
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(300, 150);
	glutCreateWindow("2D Sierpinkski Gasket");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
}