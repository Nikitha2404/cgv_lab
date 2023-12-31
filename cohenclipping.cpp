#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
#include<iostream>

void display();
using namespace std;
float xmin = -100;
float ymin = -100;
float xmax = 100;
float ymax = 100;
float xd1, yd1, xd2, yd2;


void init(void)
{

    glClearColor(0.0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-300, 300, -300, 300);
    glMatrixMode(GL_MODELVIEW);

}

int code(float x, float y)
{
    int c = 0;
    if (y > ymax)c = 8;
    if (y < ymin)c = 4;
    if (x > xmax)c = c | 2;
    if (x < xmin)c = c | 1;
    return c;
}

void cohen_Line()
{
    int c1 = code(xd1, yd1);
    int c2 = code(xd2, yd2);
    float m = (yd2 - yd1) / (xd2 - xd1);
    while ((c1 | c2) > 0)
    {
        if ((c1 & c2) > 0)
        {
            exit(0);
        }

        float xi = xd1; float yi = yd1;
        int c = c1;
        if (c == 0)
        {
            c = c2;
            xi = xd2;
            yi = yd2;
        }
        float x, y;
        if ((c & 8) > 0)
        {
            y = ymax;
            x = xi + 1.0 / m * (y - yi);
        }
        else if ((c & 4) > 0)
        {
            y = ymin;
            x = xi + 1.0 / m * (y- yi);
        }
        else if ((c & 2) > 0)
        {
            x = xmax;
            y = yi + m * (x - xi);
        }
        else if ((c & 1) > 0)
        {
            x = xmin;
            y = yi + m * (x - xi);
        }

        if (c == c1)
        {
            xd1 = x;
            yd1 = y;
            c1 = code(xd1, yd1);
        }

        if (c == c2)
        {
            xd2 = x;
            yd2 = y;
            c2 = code(xd2, yd2);
        }
    }

    display();

}

void mykey(unsigned char key, int x, int y)
{
    if (key == 'c')
    {
        cout << "Hello";
        cohen_Line();
        glFlush();
    }
}
void display()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 0.0);

    glBegin(GL_LINE_LOOP);
    glVertex2i(xmin, ymin);
    glVertex2i(xmin, ymax);
    glVertex2i(xmax, ymax);
    glVertex2i(xmax, ymin);
    glEnd();
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2i(xd1, yd1);
    glVertex2i(xd2, yd2);
    glEnd();
    glFlush();


}


int main(int argc, char** argv)
{
    printf("Enter line co-ordinates:");
    cin >> xd1 >> yd1 >> xd2 >> yd2;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Clipping");
    glutDisplayFunc(display);
    glutKeyboardFunc(mykey);
    init();
    glutMainLoop();
    return 0;
}
