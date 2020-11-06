#include <windows.h>
#include <GL/glut.h>

void mydisplay(){ //jmn display korte chai
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_POLYGON);

glVertex2d(-0.5, -0.5);
glVertex2d(-0.5, 0.5);
glVertex2d(0.5, 0.5);
glVertex2d(0.5, -0.5);

glEnd();
glFlush();
}

int main(int argc, char** argv){

glutCreateWindow("simple");
glutDisplayFunc(mydisplay);
glutMainLoop();
}
