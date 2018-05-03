#ifndef _CUBE_H_
#define _CUBE_H_

#include <GL/glut.h>
#include <GL/gl.h>

#include <vector>

using std::vector;

namespace objects {

class Cube {
 public:
  struct CubeRotation {
    GLfloat angle, x, y, z;
  };
  void rotateSelectedCubeFace(GLfloat angle);
  vector<CubeRotation> cubeStates[3][3][3];
  GLfloat getXTranslate(int x, GLint gap);
  GLfloat getYTranslate(int y, GLint gap);
  GLfloat getZTranslate(int z, GLint gap);
  GLfloat getCubeSize();
  void setCubeSize(GLfloat size);
  void resetSelectedCubeFace();
  void selectCubeFaceX(GLint start, GLint end);
  void selectCubeFaceY(GLint start, GLint end);
  void selectCubeFaceZ(GLint start, GLint end);
  GLint getXRotation();
  GLint getYRotation();
  void setXRotation(GLint x);
  void setYRotation(GLint y);
  void setRotationIncrement(GLint rot);
  void rotateX(int dir);
  void rotateY(int dir);

 private:
  GLfloat cubeSize;
  GLint xRot, yRot, startX, startY, startZ, endX,
      endY, endZ, rotIncrement;
};

};  //  namespace objects

#endif
