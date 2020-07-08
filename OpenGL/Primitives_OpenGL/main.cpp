/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

#include <math.h>

//Initialize OpenGL
void init(void) {
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,300.0,0.0,300.0);
}



void drawLines(void) {
    glClearColor(1, 1, 1, 1);

    glViewport(0, 0, 500, 500);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0, 500, 0, 500, 1, -1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    glPointSize(3.0);

    glBegin(GL_POINTS);
    glVertex2d(50, 400);
    glVertex2d(50, 440);
    glVertex2d(20, 445);
    glVertex2d(10, 405);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(180, 400);
    glVertex2d(180, 440);
    glVertex2d(150, 445);
    glVertex2d(140, 405);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2d(310, 400);
    glVertex2d(310, 440);
    glVertex2d(280, 445);
    glVertex2d(270, 405);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2d(440, 400);
    glVertex2d(440, 440);
    glVertex2d(410, 445);
    glVertex2d(400, 405);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3d(1, 1, 0);
    glVertex2d(20, 345);
    glVertex2d(10, 305);
    glVertex2d(50, 340);

    glColor3d(0, 1, 1);
    glVertex2d(50, 300);
    glVertex2d(60, 335);
    glVertex2d(70, 315);
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    glColor3d(1, 1, 0);
    glVertex2d(150, 345);
    glVertex2d(140, 305);
    glVertex2d(180, 340);

    glColor3d(0, 1, 1);
    glVertex2d(180, 300);
    glVertex2d(190, 335);
    glVertex2d(200, 315);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3d(1, 1, 0);
    glVertex2d(270, 305);
    glVertex2d(280, 340);
    glVertex2d(310, 350);


    glColor3d(0, 1, 1);
    glVertex2d(320, 340);
    glVertex2d(340, 335);
    glVertex2d(350, 315);

    glEnd();

    glBegin(GL_QUADS);
    glColor3d(1, 1, 0);
    glVertex2d(60, 200);
    glVertex2d(10, 210);
    glVertex2d(20, 260);
    glVertex2d(70, 250);

    glColor3d(0, 1, 1);
    glVertex2d(150, 240);
    glVertex2d(110, 270);
    glVertex2d(100, 220);
    glVertex2d(150, 210);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3d(1, 1, 0);
    glVertex2d(210, 210);
    glVertex2d(220, 260);
    glVertex2d(260, 200);
    glVertex2d(270, 250);

    glColor3d(0, 1, 1);
    glVertex2d(300, 220);
    glVertex2d(310, 270);
    glVertex2d(350, 210);
    glVertex2d(350, 240);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(190, 100);
    glVertex2d(140, 110);
    glVertex2d(160, 160);
    glVertex2d(200, 170);
    glVertex2d(210, 140);
    glEnd();

    glFlush();
}

int main(int argc, char**argv) {
    glutInit(&argc, argv);
    glutInitWindowPosition(10,10);
    glutInitWindowSize(500,500);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutCreateWindow("Example");
    init();
    glutDisplayFunc(drawLines);
    glutMainLoop();
}
