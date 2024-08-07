
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <cstdlib>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

const int WIDTH = 500;
const int HEIGHT = 500;

void myInit() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
    glMatrixMode(GL_MODELVIEW);
}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(0.0, 1.0, 0.0);
    glPointSize(4.0);
    glBegin(GL_TRIANGLE_STRIP);
        glVertex2i(250,150);
        glColor3d(0.0,0.0,1.0);
        glVertex2i(150,250);
        glColor3d(0.0,1.0,0.0);
        glVertex2i(150,350);
        glColor3d(1.0,0.0,0.0);
        glVertex2i(250,450);
        glColor3d(1.0,0.0,1.0);
        glVertex2i(350,450);
        glColor3d(0.0,1.0,1.0);
        glVertex2i(450,350);
        glColor3d(1.0,1.0,0.0);
        glVertex2i(450,250);
        glColor3d(1.0,1.0,1.0);
        glVertex2i(350,150);
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
        glVertex2i(50,100);
        glVertex2i(100,50);
        glColor3d(0.0,0.0,1.0);
        glVertex2i(150,100);
        glVertex2i(150,50);
        glColor3d(1.0,0.0,0.0);
        glVertex2i(250,100);
        glVertex2i(300,50);
        glColor3d(0.0,1.0,0.0);
        glVertex2i(350,100);
        glVertex2i(400,50);
    glEnd();

    glColor3d(0.0,0.0,0.0);
    glRasterPos2d(100.0,150.0);
    string s = "Text example";
    for(int i = 0; i < s.length(); i++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s[i]);
    }
    glFlush();
}

void display2(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(0.0,0.0,0.0);
    double t = 0.0, dt = 0.1;
    glBegin(GL_LINES);
        for(int i = 0; i<5000; i++) {
            double x = WIDTH/2 + WIDTH/2*cos(t);
            double y = HEIGHT/2 + HEIGHT/2*cos(t);
            glVertex2d(x,y);
            t += dt;
        }
        glEnd();
        glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(WIDTH,HEIGHT);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

    glutCreateWindow("Output Primative Examples");

    glutDisplayFunc(display2);

    myInit();
    glutMainLoop();

    return EXIT_SUCCESS;
}
