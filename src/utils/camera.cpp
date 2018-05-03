#include "camera.h"

namespace utils {

GLdouble Camera::eyeX = 0.0;
GLdouble Camera::eyeY = 80.0;
GLdouble Camera::eyeZ = 200.0;
GLdouble Camera::centerX = 0.0;
GLdouble Camera::centerY = 0.0;
GLdouble Camera::centerZ = 0.0;
GLdouble Camera::upX = 0.0;
GLdouble Camera::upY = 1.0;
GLdouble Camera::upZ = 0.0;

GLfloat Camera::getAngle() {
  return angle;
}

void Camera::setAngle(GLfloat angle) {
  this->angle = angle;
}

GLint Camera::getGap() {
  return gap;
}

void Camera::setGap(GLint gap) {
  this->gap = gap;
}

GLint Camera::getGapIncrement() {
  return gapIncrement;
}

void Camera::setGapIncrement(GLint increment) {
  gapIncrement = increment;
}

void Camera::zoomIn() {
  gap += gapIncrement;
}

void Camera::zoomOut() {
  gap -= gapIncrement;
}

GLfloat Camera::getFAspect() {
  return fAspect;
}

void Camera::setFAspect(GLfloat w, GLfloat h) {
  fAspect = w / h;
}

}
