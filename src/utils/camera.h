#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <GL/glut.h>
#include <GL/gl.h>

namespace utils {

class Camera {
 public:
  static GLdouble eyeX;
  static GLdouble eyeY;
  static GLdouble eyeZ;
  static GLdouble centerX;
  static GLdouble centerY;
  static GLdouble centerZ;
  static GLdouble upX;
  static GLdouble upY;
  static GLdouble upZ;

  GLfloat getAngle();
  void setAngle(GLfloat angle);

  GLint getGap();
  void setGap(GLint gap);

  GLint getGapIncrement();
  void setGapIncrement(GLint increment);

  GLfloat getFAspect();
  void setFAspect(GLfloat w, GLfloat width);

  void zoomIn();
  void zoomOut();

 private:
  GLint gap, gapIncrement;
  GLfloat angle, fAspect;
};

};  //  namespace utils

#endif
