#include<stdio.h>
#include<GL/glut.h>
void myinit()
{
    glMatrixMode(GL_PROJECTION_MATRIX);
    glLoadIdentity();
    gluOrtho2D(-100,100,-100,100);
    glMatrixMode(GL_MODELVIEW);
}
void display()
{
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-50,-50);
    glVertex2f(-50,50);
    glVertex2f(50,50);
    glVertex2f(50,-50);
    glEnd();
    glFlush();
}
void reshape(int w,int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION_MATRIX);
    glLoadIdentity();
    float t1 = (float)w/(float)h;
    float t2 = (float)h/(float)w;
    if(w>h)
    gluOrtho2D(-100*t1,100*t1,-100,100);
    else
    gluOrtho2D(-100,100,-100*t2,100*t2);
    glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();
}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(200,200);
    glutInitWindowPosition(300,150);
    glutCreateWindow("Reshape");
    myinit();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
}
