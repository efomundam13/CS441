//
// Lab1 - Sierpinski Gasket Program
//

#include <math.h>
#include <gl/glut.h>
#include <iostream>
using namespace std;

class GLintPoint2 {				// simple two-dim point class
public:
	GLint x, y;
};

GLintPoint2 vertex[3];
int vtx = -1;

void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);		// white background
    glColor3f(1.0, 0.0, 0.0);				// draw in red

    //#3 on the Lab
    //glClearColor(0.0, 0.0, 1.0, 1.0);       // blue background
    //glColor3f(0.0, 1.0, 0.0);				// draw in green

								// set up viewing
								// 500 x 500 window with origin lower left
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);

    //#5 on Lab
    //gluOrtho2D(0.0, 400.0, 0.0, 400.0);
    //gluOrtho2D(0.0, 500.0, 0.0, 1000.0);

    glMatrixMode(GL_MODELVIEW);
								// initialize vertices of triangle
    vertex[0].x = 0.0;
    vertex[0].y = 0.0;
    vertex[1].x = 250.0;
    vertex[1].y = 500.0;
    vertex[2].x = 500.0;
    vertex[2].y = 0.0;
}

float dist(float x1, float y1, float x2, float y2)
//
// returns distance between points (x1,y1) and (x2,y2)
//
{
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

//#7 on the Lab
void colorPoint(GLintPoint2 p) {
    float distToRed = dist(p.x, p.y, vertex[0].x, vertex[0].y);
    float distToGreen = dist(p.x, p.y, vertex[1].x, vertex[1].y);
    float distToBlue = dist(p.x, p.y, vertex[2].x, vertex[2].y);
    float totalDist = distToRed + distToGreen + distToBlue;

    float red = (totalDist - distToRed) / totalDist;
    float green = (totalDist - distToGreen) / totalDist;
    float blue = (totalDist - distToBlue) / totalDist;

    glColor3f(red, green, blue);
}

void display( void )
//
// display callback function
//
{
    int j, k;
    GLintPoint2 p = vertex[0];

    glClear(GL_COLOR_BUFFER_BIT);	// clear the window
    for( k=0; k<50000; k++)			// draw Sierpinski triangle
    {
		j=rand()%3;						// pick a vertex at random
		p.x = (p.x+vertex[j].x)/2.0;	// Compute point halfway between selected
		p.y = (p.y+vertex[j].y)/2.0;    //   vertex and old point

		//7 on the Lab
		colorPoint(p); // set color based on distance to vertices

		//#4 on the Lab
		//if ((p.x + p.y) % 2 == 0)
            //glColor3f(1.0, 0.0, 0.0); // red for even sum
        //else
            //glColor3f(0.0, 1.0, 0.0); // green for odd sum

		glBegin(GL_POINTS);
        glVertex2f(p.x, p.y);
		glEnd();

		//#2 in the Lab
		if(k % 1 == 0) // Flush every 10 points
        {
            glFlush();
        }
	}
	glFlush();						// flush buffers
 }

int main(int argc, char** argv)
{
                                            // Standard GLUT initialization
    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);

    //#6 on the Lab
    //glutInitWindowSize(400,400);
    //glutInitWindowSize(600,400);
    //glutInitWindowPosition(100,200);

    glutInitWindowSize(500,500);			// 500 x 500 pixel window
    glutInitWindowPosition(0,0);			// place window top left on display
    glutCreateWindow("Sierpinski Gasket");	// window title
    glutDisplayFunc(display);				// register callback routines
    myInit();

    glutMainLoop();							// enter event loop
    return 0;
}

