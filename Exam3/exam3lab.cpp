#include <iostream>
#include <gl/Gl.h>
#include <gl/Glu.h>
#include <gl/glut.h>
#include <cmath>
#include <ctime>
using namespace std;

int width = 800;
int height = 800;

const double PI = 4.0*atan(1.0);

struct point
{
    double x, y;
};

struct color {
    float r, g, b;
};

color starColor = {0.0f, 0.0f, 0.0f};
point center;
double scale = 1.0;
double rotation = 0.0;

void drawSquares() {
    int side = 50;
    color colors[6] = {{1.0f, 0.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f},
    {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f, 1.0f}};
    for(int i = 0; i < 6; i++) {
        glColor3f(colors[i].r, colors[i].g, colors[i].b);
        glBegin(GL_QUADS);
        glVertex2i(0, height - i * side);
        glVertex2i(side, height - i * side);
        glVertex2i(side, height - (i + 1) * side);
        glVertex2i(0, height - (i + 1) * side);
        glEnd();
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2i(0, height - i * side);
        glVertex2i(side, height - i * side);
        glVertex2i(side, height - (i + 1) * side);
        glVertex2i(0, height - (i + 1) * side);
        glEnd();
    }
}

void drawStar(point p) {
    int numPoints = 5;
    double radius = 50;
    double twoPi = 2.0 * 3.14159;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    for(int i = 0; i <= 2 * numPoints; i++) {
        double theta = i * twoPi / numPoints;
        double x = p.x + radius * cos(theta);
        double y = p.y + radius * sin(theta);
        if(i % 2 == 0) {
            x = p.x + radius/2 * cos(theta);
            y = p.y + radius/2 * sin(theta);
        }
        glVertex2d(x, y);
    }
    glEnd();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glColor3f(starColor.r, starColor.g, starColor.b);
	glPushMatrix();
	glTranslated(center.x, center.y, 0.0);
	glRotated(rotation, 0.0, 0.0, 1.0);
	glScaled(scale, scale, 1.0);
	drawStar({0, 0});
	glPopMatrix();
	drawSquares();
	glFlush();
}

void reshape(int w, int h)
{
    width = w;
    height = h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, width, 0.0, height);
	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, width, height);
}

void mouse(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        int side = 50;
        int i = (height - y) / side;
        if(x < side && i < 6) {
            if(i % 2 == 0) {
                starColor.r += 0.1f * (i == 0);
                starColor.g += 0.1f * (i == 2);
                starColor.b += 0.1f * (i == 4);
            } else {
                starColor.r -= 0.1f * (i == 1);
                starColor.g -= 0.1f * (i == 3);
                starColor.b -= 0.1f * (i == 5);
            }
        } else {
            center.x = x;
            center.y = height - y;
        }
        glutPostRedisplay();
    }
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key) {
        case '+':
            scale *= 2.0;
            break;
        case '-':
            scale /= 2.0;
            break;
        case 'c':
            rotation += 5.0;
            break;
        case 'C':
            rotation -= 5.0;
            break;
        case 'q':
            exit(0);
    }
    glutPostRedisplay();
}

void specialKeys(int key, int x, int y)
{
    switch(key) {
        case GLUT_KEY_UP:
            center.y += 10;
            break;
        case GLUT_KEY_DOWN:
            center.y -= 10;
            break;
        case GLUT_KEY_LEFT:
            center.x -= 10;
            break;
        case GLUT_KEY_RIGHT:
            center.x += 10;
            break;
    }
    glutPostRedisplay();
}

void myInit (void)
{
    glClearColor (1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	center.x = width/2;
	center.y = height/2;
	gluOrtho2D(0.0, width, 0.0, height);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(width, height);
   glutCreateWindow("Lab Final");
   glutDisplayFunc(display);
   glutMouseFunc(mouse);
   glutKeyboardFunc(keyboard);
   glutSpecialFunc(specialKeys);
   myInit();
   glutMainLoop();
}
