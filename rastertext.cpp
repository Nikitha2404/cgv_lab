
#include<GL/glut.h>
#include<iostream>
#include<cstring>
using namespace std;

char str[40];
int cx1 = 50, cy1 = 100, cx2 = 20, cy2 = 180, d = 10;

void myinit()
{
	glMatrixMode(GL_PROJECTION_MATRIX);
	glLoadIdentity();
	gluOrtho2D(0, 200, 0, 200);
	glMatrixMode(GL_MODELVIEW);
}

void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1, 0, 0);
	glRasterPos2i(cx1, cy1);

	int i;

	glRasterPos2i(cx1, cy1);
	for (i = 0; i < strlen(str); i++)
	{

		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
	}

	glColor3f(0, 0, 1);
	for (i = 0; i < strlen(str); i++)
	{
		glRasterPos2i(cx2,cy2 - d * i);
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str[i]);
	}

	glFlush();
}

int main(int argc,char **argv)
{
    glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(300, 150);
	cout << "Enter the string:\n";
	cin >> str;
	glutCreateWindow("Text");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
}