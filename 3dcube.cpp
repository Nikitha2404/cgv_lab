#include<stdlib.h>
#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
float v[8][3] = { {-1,-1,1},{-1,1,1},{1,1,1},{1,-1,1},{-1,-1,-1},{-1,1,-1},{1,1,-1},{1,-1,-1} };
float p[8][3] = { {0,0,1},{0,1,1},{1,1,1},{1,0,1},{0,0,0},{0,1,0},{1,1,0},{1,0,0} };
float theta[3] = { 0,0,0 };
int flag = 2;

void myinit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2, 2, -2, 2, -2, 2);
    glMatrixMode(GL_MODELVIEW);
}
void idlefunc()
{
    theta[flag]+=0.5;
    if (theta[flag] > 360)theta[flag] = 0;
    glutPostRedisplay();
}
void mousefunc(int button, int status, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && status == GLUT_DOWN)
        flag = 2;
    if (button == GLUT_MIDDLE_BUTTON && status == GLUT_DOWN)
        flag = 1;
    if (button == GLUT_RIGHT_BUTTON && status == GLUT_DOWN)
        flag = 0;
}
void drawpoly(int a, int b, int c, int d)
{
    glBegin(GL_POLYGON);
    glVertex3fv(v[a]);
    glVertex3fv(v[b]);
    glVertex3fv(v[c]);
    glVertex3fv(v[d]);
    glEnd();
}
void colorcube()
{
    glColor3fv(p[0]);
    drawpoly(0, 1, 2, 3);
    glColor3fv(p[1]);
    drawpoly(0, 1, 5, 4);
    glColor3fv(p[3]);
    drawpoly(1, 5, 6, 2);
    glColor3fv(p[5]);
    drawpoly(4, 5, 6, 7);
    glColor3fv(p[6]);
    drawpoly(3, 2, 6, 7);
    glColor3fv(p[7]);
    drawpoly(0, 4, 7, 3);
}
void display()
{
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // glColor3f(1, 0, 0);
    glEnable(GL_DEPTH_TEST);
    glLoadIdentity();
    glRotatef(theta[0], 1, 0, 0);//x
    glRotatef(theta[1], 0, 1, 0);//y
    glRotatef(theta[2], 0, 0, 1);//z
    colorcube();
    glFlush();
    glutSwapBuffers();
}
int main(int argc,char *argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("cube rotation");
    myinit();
    glutDisplayFunc(display);
    glutMouseFunc(mousefunc);
    glutIdleFunc(idlefunc);
    glutMainLoop();
    return 0;
}
