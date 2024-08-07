#include <GL/glut.h>
#include <iostream>
using namespace std;

const int WIDTH = 500;
const int HEIGHT = 500;
int width = WIDTH;
int height = HEIGHT;

const int DRAW_POINTS = 1;
const int DRAW_LOOP = 2;
int state = DRAW_POINTS;

struct point {
    int x;
    int y;
} points[4];
int npoints = 0;

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    if(state == DRAW_POINTS) // Corrected here
        glBegin(GL_POINTS);
    else
        glBegin(GL_LINE_LOOP);
    for(int i=0; i<npoints; i++)
        glVertex2i(points[i].x, points[i].y);
    glEnd(); // Added this line to end the glBegin
    glFlush();
}

void myKeyboard(unsigned char key, int x, int y) {
    switch(key) {
        case 'q' : exit(0);
    }
}

void colorMenu(int val) {
    switch(val) {
    case 0: glColor3f(0.0,0.0,0.0);break;
    case 1: glColor3f(1.0,0.0,0.0);break;
    case 2: glColor3f(0.0,1.0,0.0);break;
    }
}

void myReshape(int w, int h) {
    width = w;
    height = h;
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,w,0,h);
    glMatrixMode(GL_MODELVIEW);
}

void myInit()
{
    glClearColor(1,1,1,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,WIDTH,0,HEIGHT);
    glMatrixMode(GL_MODELVIEW);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(3.0);
    glutCreateMenu(colorMenu);
    glutAddMenuEntry("black", 0);
    glutAddMenuEntry("red", 1);
    glutAddMenuEntry("green", 2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}


void myMouse(int button, int ButtonState, int x, int y) {
    y = height - y;
    if(button == GLUT_LEFT_BUTTON && ButtonState == GLUT_DOWN) {
        if (npoints == 4)
        npoints = 0;
    points[npoints].x=x;
    points[npoints].y=y;
    npoints++;
    if(npoints == 4)
        state = DRAW_LOOP;
    else
        state = DRAW_POINTS;
    glutPostRedisplay();
    }
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(WIDTH,HEIGHT);
    glutInitWindowPosition(200,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Callback Examples");
    glutMouseFunc(myMouse);
    glutKeyboardFunc(myKeyboard);
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
    myInit();
    glutMainLoop();

    return EXIT_SUCCESS;
}

