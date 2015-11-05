#include<GL/glut.h>
#include<GL/gl.h>

//#include "stdafx.h"
using namespace std;
void init(void){
  glClearColor(0.0,0.0,0.0,0.0);
  glShadeModel(GL_SMOOTH);
  gluOrtho2D(0.0,640.0,0.0,480.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
}

void display(void){
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_TRIANGLES);
  glColor3f(1.0,0.0,0.0);
  glVertex2f(50.0,50.0);
  glColor3f(0.0,1.0,0.0);
  glVertex2f(250.0,50.0);
  glColor3f(0.0,0.0,1.0);
  glVertex2f(50.0,250.0);
  glEnd();
  glFlush();
}

int main(int argc, char **argv){
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500,500);
  glutInitWindowPosition(100,100);
  glutCreateWindow("Shade");
  init();
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
