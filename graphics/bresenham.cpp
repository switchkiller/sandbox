/*---------------------
| Author: switchkiller |
----------------------*/
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<GL/glut.h>

int win_width = 512;
int win_height = 512;
int xx0, yy0;
int xx1, yy1;
int numpoints = 0;
int linetype = 0;

//Basic Bresenham line drawing (working only in first octant)

void line1 (int x0, int y0, int x1, int y1)
{
  int deltax = x1 - x0;
  int deltay = y1 - y0;
  float error = 0;
  float newerr = 0;
  float deltaerr = (float) deltay / (float) deltax;
  int y = y0;
  int newy = y0;
  glPointSize(1.0);
  glColor3f(0.0, 0.0, 1.0);
  glBegin(GL_POINTS);
  for ()
}
