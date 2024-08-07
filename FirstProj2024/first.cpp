#include <GL/glut.h>
#include <iostream>
using namespace std;

const int WIDTH = 500;
const int HEIGHT = 500;

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);         // clear the window
    glColor3f(0.0, 1.0, 0.0);             // set color to green
    glBegin(GL_LINE_STRIP);
        glVertex2d(0.0, 0.0);
        glVertex2d(1.0, 0.0);
        glVertex2d(1.0, 1.0);
        glVertex2d(2.0, 1.0);
        glVertex2d(2.0, 2.0);
        glVertex2d(3.0, 2.0);
    glEnd();
    glFlush();
}

void myInit()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);     // black background
    glMatrixMode(GL_PROJECTION);          // set up view volume and projection
    glLoadIdentity();
    gluOrtho2D(-5.0, 5, -5.0, 5);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("first");
    glutDisplayFunc(display);
    myInit();
    glutMainLoop();
    return 0;
}
