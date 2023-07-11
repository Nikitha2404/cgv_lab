#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <GL/glut.h>

using namespace std;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

const int BAR_WIDTH = 5;
const int BAR_HEIGHT_MAX = 400;
const int BAR_SPACING = 1;

int bars[SCREEN_WIDTH / (BAR_WIDTH + BAR_SPACING)];
int num_bars = sizeof(bars) / sizeof(*bars);

void init()
{
    glMatrixMode(GL_PROJECTION_MATRIX);
	glLoadIdentity();
	gluOrtho2D(-50, 50, -50, 50);
	glMatrixMode(GL_MODELVIEW);
}

void drawBars()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glTranslatef(-SCREEN_WIDTH / 2, -SCREEN_HEIGHT / 2, 0);

    glColor3f(1.0f, 1.0f, 1.0f);
    for (int i = 0; i < num_bars; i++)
    {
        glRecti(i * (BAR_WIDTH + BAR_SPACING), 0, (i + 1) * BAR_WIDTH + i * BAR_SPACING, bars[i]);
    }

    glutSwapBuffers();
}


bool sortingDone = true;

void bubbleSort()
{
    sortingDone = false;
    for (int i = 0; i < num_bars - 1; i++)
    {
        for (int j = 0; j < num_bars - i - 1; j++)
        {
            if (bars[j] > bars[j + 1])
            {
                swap(bars[j], bars[j + 1]);
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
            }
        }
    }
    sortingDone = true;
    glutPostRedisplay();
}

void insertionSort()
{
    sortingDone = false;
    for (int i = 1; i < num_bars; i++)
    {
        int key = bars[i];
        int j = i - 1;

        while (j >= 0 && bars[j] > key)
        {
            bars[j + 1] = bars[j];
            j--;
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        bars[j + 1] = key;
    }
    sortingDone = true;
    glutPostRedisplay();
}

void selectionSort()
{
    sortingDone = false;
    for (int i = 0; i < num_bars - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < num_bars; j++)
        {
            if (bars[j] < bars[min_idx])
            {
                min_idx = j;
            }
        }
        swap(bars[i], bars[min_idx]);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    sortingDone = true;
    glutPostRedisplay();
}


void handleKey(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'b':
            printf("Sorting with Bubble Sort\n");
            std::thread(bubbleSort).detach();
            break;
        case 'i':
            printf("Sorting with Insertion Sort\n");
            std::thread(insertionSort).detach();
            break;
        case 's':
            printf("Sorting with Selection Sort\n");
            std::thread(selectionSort).detach();
            break;
        // case 'm':
        //     printf("Sorting with Merge Sort\n");
        //     std::thread(mergeSort, 0, num_bars - 1).detach();
        //     break;
        case 27: // Escape key
            exit(0);
            break;
        default:
            break;
    }
}


int main(int argc, char** argv)
{
    srand(time(NULL));
    for (int i = 0; i < num_bars; i++)
    {
        bars[i] = rand() % BAR_HEIGHT_MAX + 1;
    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    glutCreateWindow("Sorting Visualization");
    glutDisplayFunc(drawBars);
    glutKeyboardFunc(handleKey);
    
    init();
    glutMainLoop();

    return 0;
}
