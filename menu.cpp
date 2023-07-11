#include<stdlib.h>
#include<stdio.h>
#include<GL/glut.h>
float x1,x2,x3,x4,yy1,y2,y3,y4;
void d_menu(int op)
{
	if(op==1)
		glColor3f(1.0,0.0,0.0);
	else if(op==2)
		glColor3f(0.0,1.0,0.0);
	else if(op==3)
		glColor3f(0.0,0.0,1.0);
	else if(op==4)
		exit(0);
	glutPostRedisplay();
}

void display()
{
	x1=200.0;yy1=200.0;x2=100.0;y2=300.0;
	x3=200.0;y3=400.0;x4=300.0;y4=300.0;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_LOOP);
	glVertex2f(x1,yy1);
	glVertex2f(x2,y2);
	glVertex2f(x3,y3);
	glVertex2f(x4,y4);
	glEnd();
	glFlush();
}

void myinit()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(1.0,0.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,499.0,0.0,499.0);
}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("polygon");
	glutCreateMenu(d_menu);
	glutAddMenuEntry("Red",1);
	glutAddMenuEntry("Green",2);
	glutAddMenuEntry("Blue",3);
	glutAddMenuEntry("Quit",4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	myinit();
	glutDisplayFunc(display);		
	glutMainLoop();
}