#include<GL/glut.h>
#include<stdlib.h>
#include<cmath>
#include<stdio.h>
#include<iostream>
using namespace std;
float x1=10, x2=50, y11=10, y2=50;
void display()
{
	float dy, dx, step, x, y, k, Xin, Yin;
	dx = x2 - x1;
	dy = y2 - y11;
	if (abs(dx) > abs(dy))
	{
		step = abs(dx);
	}
	else
		step = abs(dy);

	Xin = dx / step;
	Yin = dy / step;
	x = x1;
	y = y11;
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();

	for (k = 1; k <= step; k++)
	{
		x = x + Xin;
		y = y + Yin;

		glBegin(GL_POINTS);
		glVertex2i(x, y);
		glEnd();
	}
	glFlush();
}

void init()
{
	glClearColor(0.7, 0.7, 0.7, 0.7);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	/*cout<<"Enter the value of x1 : ";
	cin>>x1;
	cout << "Enter the value of y1 : ";
	cin>>y1;
	cout<<"Enter the value of x2 :";
	cin>>x2;
	cout<<"Enter the value of y2 : ";
	cin>>y2;*/
	glutCreateWindow("DDA Line Algo");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}