#include<GL/freeglut.h>

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5f, 0.5f, 0.5f);
	glBegin(GL_POLYGON);
		glVertex2f(10,10);
		glVertex2f(70,10);
		glVertex2f(70,40);
		glVertex2f(10,40);
	glEnd();

	glFlush();
}

void Init(){
	glClearColor(0.1, 0.1, 0.1,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,640.0,0.0,480.0);
}

int main(int argc, char* argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(1024,768);
	glutInitWindowPosition(480,400);
	glutCreateWindow("Heelo");
	
	Init();
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}