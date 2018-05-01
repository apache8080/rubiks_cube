#include "cube.h"

namespace objects {

Cube::Cube(double dim, int faces) {
  this->dim = dim;
  this->faces = faces;
}

void Cube::display() {
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();

  glRotatef(rotate_x, 1.0, 0.0, 0.0);
  glRotatef(rotate_y, 0.0, 1.0, 0.0);

  glBegin(GL_POLYGON);

  glColor3f(1.0, 0.0, 0.0);
  glVertex3f(dim, -dim, -dim);

  glColor3f(0.0, 1.0, 0.0);
  glVertex3f(dim, dim, -dim);

  glColor3f(0.0, 0.0, 1.0);
  glVertex3f(-dim, dim, -dim);

  glColor3f(1.0, 0.0, 1.0);
  glVertex3f(-dim, -dim, -dim);

  glEnd();

  glBegin(GL_POLYGON);
  glColor3f(1.0, 1.0, 1.0);
  glVertex3f(dim, -dim, dim);
  glVertex3f(dim, dim, dim);
  glVertex3f(-dim, dim, dim);
  glVertex3f(-dim, -dim, dim);
  glEnd();

  glBegin(GL_POLYGON);
  glColor3f(1.0, 0.0, 1.0);
  glVertex3f(dim, -dim, -dim);
  glVertex3f(dim, dim, -dim);
  glVertex3f(dim, dim, dim);
  glVertex3f(dim, -dim, dim);
  glEnd();

  glBegin(GL_POLYGON);
  glColor3f(0.0, 1.0, 0.0);
  glVertex3f(-dim, -dim, dim);
  glVertex3f(-dim, dim, dim);
  glVertex3f(-dim, dim, -dim);
  glVertex3f(-dim, -dim, -dim);
  glEnd();

  glBegin(GL_POLYGON);
  glColor3f(0.0, 0.0, 1.0);
  glVertex3f(dim, dim, dim);
  glVertex3f(dim, dim, -dim);
  glVertex3f(-dim, dim, -dim);
  glVertex3f(-dim, dim, dim);
  glEnd();

  glBegin(GL_POLYGON);
  glColor3f(1.0, 0.0, 0.0);
  glVertex3f(dim, -dim, -dim);
  glVertex3f(dim, -dim, dim);
  glVertex3f(-dim, -dim, dim);
  glVertex3f(-dim, -dim, -dim);
  glEnd();

  glFlush();
  glutSwapBuffers();
}

void rotateX(double dx) {
  rotate_x += dx;
}

void rotateY(double dy) {
  rotate_y = dy;
}

}
