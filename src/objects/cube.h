#ifndef _CUBE_H_
#define _CUBE_H_

#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <cmath>
#include <vector>

namespace objects {

class Cube {
 public:
  Cube(double dim, int faces);
  void rotateX(double dx);
  void rotateY(double dy);
  void display();

 private:
  double rotate_y;
  double rotate_x;
  double dim;
  int faces;
};

};  //  namespace objects

#endif
