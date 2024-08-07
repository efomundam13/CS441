/*
Name: Manny Fomundam
Date: January 31, 2023
Professor: John Bonomo
*/

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <cmath>

const double PI = 4.0*atan(1.0);

//1a. Function to draw a filled circle
void drawCircle(float cx, float cy, float r) {
    glBegin(GL_POLYGON);
    for(int i=0; i<360; i++) {
        float theta = i*PI/180;
        float x = r*cos(theta) + cx;
        float y = r*sin(theta) + cy;
        glVertex2f(x, y);
    }
    glEnd();
}

//1b. Function to draw an arc of a circle
void drawArc(float cx, float cy, float r, float startAngle, float endAngle) {
    glBegin(GL_LINE_STRIP);
    for(float i = startAngle; i <= endAngle; i += 1.0) {
        float theta = i*PI/180;
        float x = r*cos(theta) + cx;
        float y = r*sin(theta) + cy;
        glVertex2f(x, y);
    }
    glEnd();
}

// 2. display() function for IBM logo:
void displayIBMLogo() {
    glClear(GL_COLOR_BUFFER_BIT);  // Clear the screen

    //Creates the letter "I"
    glColor3d(0,0,1);
    glRecti(2, 0, 4, 20);
    glRecti(0, 18, 6, 20);
    glRecti(0, 0, 6, 2);

    glTranslatef(8,0,0);

    //Creates the letter "B"
    glRecti(0, 0, 2, 20);  // Vertical bar of "B"
    drawArc(2, 15, 5, -90, 90);  // Upper curve of "B"
    drawArc(2, 5, 5, -90, 90);   // Lower curve of "B"

    glTranslatef(8,0,0);

    //Created the letter "M"
    glRecti(0, 0, 2, 20);   // Draw left vertical bar of "M"

      // Draw first slanted bar of "M" connecting to the top of the left vertical bar
    glBegin(GL_QUADS);
    glVertex2i(2, 20);
    glVertex2i(3, 0);
    glVertex2i(4, 0);
    glVertex2i(3, 20);
    glEnd();

    // Draw second slanted bar of "M" connecting to the top of the right vertical bar
    glBegin(GL_QUADS);
    glVertex2i(4, 0);
    glVertex2i(5, 20);
    glVertex2i(6, 20);
    glVertex2i(5, 0);
    glEnd();

    glRecti(6, 0, 8, 20);   // Draw right vertical bar of "M"

    int sHeight = 21/7;

    // Draw seven white horizontal lines
    glColor3d(1, 1, 1);  // Set color to white
    for (int i = 0; i < 8; ++i) {
        glRecti(0 - 20, (i * sHeight) - 0.25, 20, (i * sHeight)  + 0.25);
    }
    glFlush();
}

// 3. display function for fading circle:
void displayFadingCircle() {
    glClear(GL_COLOR_BUFFER_BIT);

    int numCircles = 360;
    float maxRadius = 50.0f;

    for (int i = 360; i > 0; i--) {
        float radius = maxRadius * ((float)i / numCircles);
        float color = 0 + ((float)i / numCircles);
        glColor3f(color, color, color);
        drawCircle(50, 50, radius);
    }

    glColor3f(0,0,0);
    drawCircle(50,50,5);

    glFlush();  // Force rendering
}

/*
You would set red to 1,0, blue and green would be set to color
for  the center to start at red and then fade to white.
Also the color of the small circle is changed from
glColor3f(0,0,0) to glColor3f(1,0,0).
*/


// 4. Routine for clock outline:
void drawClockShape(float width, float height, float a, float b) {
 // Draw the underlying rectangle
    glBegin(GL_QUADS);
    glVertex2f(0, 0);
    glVertex2f(width, 0);
    glVertex2f(width, height);
    glVertex2f(0, height);
    glEnd();

    // Draw the larger circle
    drawCircle(width/2, height/1.1, b);

    drawArc(width*.73, height*1.5, a, 180, 270); // top right arc
    drawArc(width*.27, height*1.5, a, 270, 360);   // top left arc
}

void displayClock() {
    glColor3f(0.0, 0.0, 0.0);  // Set color to white

    // Assuming width, height, a, and b are given
    glColor3d(1,1,1);
    drawClockShape(60, 10, 5, 10.5);

    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);  // Adjusted window size
    glutCreateWindow("HW 1 Solutions");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(0, 100, 0, 100);  // Adjusted view volume

    // Choose the display function you want to test
    // glutDisplayFunc(displayIBMLogo);
    // glutDisplayFunc(displayFadingCircle);
    // glutDisplayFunc(displayClock);

    glutMainLoop();
    return 0;
}
