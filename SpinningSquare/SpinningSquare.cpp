#include <iostream>
#include <windows.h>
#include <cmath>
#include <gl/glut.h>
using namespace std;

const int WIDTH = 500;
const int HEIGHT = 500;
const double PI = 4.0*atan(1.0);

float rotate1, inc1;
float red, blue, green;
float redInc, blueInc, greenInc;

const bool DOUBLE_BUFFERING = true;

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_QUADS);
        double x1 = 3.0*cos(rotate1);
        double y1 = 3.0*sin(rotate1);
		glColor3f(red, green, blue);
		glVertex2f(x1, y1);
        x1 = 3.0*cos(rotate1+PI/2);
        y1 = 3.0*sin(rotate1+PI/2);
		glColor3f(1-red, green, blue);
		glVertex2f(x1, y1);
        x1 = 3.0*cos(rotate1+PI);
        y1 = 3.0*sin(rotate1+PI);
		glColor3f(red, 1-green, blue);
		glVertex2f(x1, y1);
        x1 = 3.0*cos(rotate1+3*PI/2);
        y1 = 3.0*sin(rotate1+3*PI/2);
		glColor3f(red, green, 1-blue);
		glVertex2f(x1, y1);
	glEnd();
	if (DOUBLE_BUFFERING)
        glutSwapBuffers();
    else
        glFlush();
}

void idle()
{
	rotate1 += inc1;
	if (rotate1 > 360.0)
		rotate1 -= 360;
	red += redInc;
	if (red < 0) {
		redInc *= -1;
		red = redInc;
	}
	else if (red > 1) {
		redInc *= -1;
		red = 1-redInc;
	}
	green += greenInc;
	if (green < 0) {
		greenInc *= -1;
		green = greenInc;
	}
	else if (green > 1) {
		greenInc *= -1;
		green = 1-greenInc;
	}
	blue += blueInc;
	if (blue < 0) {
		blueInc *= -1;
		blue = blueInc;
	}
	else if (blue > 1) {
		blueInc *= -1;
		blue = 1-blueInc;
	}
	glutPostRedisplay();
}

void myinit()
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-5.0, 5, -5.0, 5);

	rotate1 = 0.0;
	inc1 = -0.0005;
	red = 1.0, green = 0.5, blue = 0.0;
	redInc = -0.0005, greenInc = blueInc = 0.0003;
}

void mouseFunc(int button, int state, int x, int y)
{
	int mult;
	if (state == GLUT_DOWN) {
		if (glutGetModifiers() == GLUT_ACTIVE_SHIFT)
			mult = -1;
		else
			mult = 1;
		if (button == GLUT_LEFT_BUTTON)
			inc1 += mult*0.1;
	}
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    if (DOUBLE_BUFFERING)
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    else
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Spinning Square");
    myinit();
    glutDisplayFunc(display);
    glutIdleFunc(idle);
	glutMouseFunc(mouseFunc);
    glutMainLoop();
}
