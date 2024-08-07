#include <iostream>
#include <gl/Gl.h>
#include <gl/Glu.h>
#include <gl/glut.h>
#include <cmath>
using namespace std;

int width = 800;
int height = 800;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    gluLookAt(20.0, 20.0, 20.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(3.0);
    glBegin(GL_LINES);
        glVertex3i(0.0, 0.0, 0.0);
        glVertex3i(10.0, 0.0, 0.0);
        glVertex3i(0.0, 0.0, 0.0);
        glVertex3i(0.0, 10.0, 0.0);
        glVertex3i(0.0, 0.0, 0.0);
        glVertex3i(0.0, 0.0, 10.0);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3i(-5, -5, 5);
        glVertex3i(-5, 5, 5);
        glVertex3i(5, 5, 5);
        glVertex3i(5, -5, 5);
        glColor3f(1.0, 1.0, 0.0);
        glVertex3i(-5, -5, -5);
        glVertex3i(-5, 5, -5);
        glVertex3i(5, 5, -5);
        glVertex3i(5, -5, -5);
        glColor3f(0.0, 1.0, 0.0);
        glVertex3i(5, -5, -5);
        glVertex3i(5, -5, 5);
        glVertex3i(5, 5, 5);
        glVertex3i(5, 5, -5);
        glColor3f(0.0, 1.0, 1.0);
        glVertex3i(-5, -5, -5);
        glVertex3i(-5, -5, 5);
        glVertex3i(-5, 5, 5);
        glVertex3i(-5, 5, -5);
        glColor3f(0.0, 0.0, 1.0);
        glVertex3i(-5, 5, -5);
        glVertex3i(5, 5, -5);
        glVertex3i(5, 5, 5);
        glVertex3i(-5, 5, 5);
        glColor3f(1.0, 0.0, 1.0);
        glVertex3i(-5, -5, -5);
        glVertex3i(5, -5, -5);
        glVertex3i(5, -5, 5);
        glVertex3i(-5, -5, 5);
    glEnd();
    glutSwapBuffers();

}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 'q')
        exit(0);
}

void myInit (void)
{
	glClearColor (1.0, 1.0, 1.0, 1.0);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-20.0, 20.0, -20.0, 20.0, 0.0, 50.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize(width, height);
   glutCreateWindow("3D viewing");
   glutDisplayFunc(display);
   glutKeyboardFunc(keyboard);
   myInit();
   glutMainLoop();
}
