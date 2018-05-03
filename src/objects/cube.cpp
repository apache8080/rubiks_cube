#include "cube.h"

namespace objects {

GLfloat Cube::getCubeSize() {
  return cubeSize;
}

void Cube::setCubeSize(GLfloat size) {
  cubeSize = size;
}

void Cube::rotateX(int dir) {
  if (dir == 1) {
    xRot = (xRot + rotIncrement) % 360;
  } else {
    xRot = (xRot - rotIncrement) % 360;
  }
}

void Cube::rotateY(int dir) {
  if (dir == 1) {
    yRot = (yRot + rotIncrement) % 360;
  } else {
    yRot = (yRot - rotIncrement) % 360;
  }
}

void Cube::setXRotation(GLint x) {
  xRot = x;
}

void Cube::setYRotation(GLint y) {
  yRot = y;
}

GLint Cube::getXRotation() {
  return xRot;
}

GLint Cube::getYRotation() {
  return yRot;
}

void Cube::setRotationIncrement(GLint rot) {
  rotIncrement = rot;
}

void Cube::selectCubeFaceX(GLint start, GLint end) {
  startX = start;
  endX = end;
}

void Cube::selectCubeFaceY(GLint start, GLint end) {
  startY = start;
  endY = end;
}

void Cube::selectCubeFaceZ(GLint start, GLint end) {
  startZ = start;
  endZ = end;
}

void Cube::rotateSelectedCubeFace(GLfloat angle) {
  vector<CubeRotation> cubeFaces[3][3];
  int id;
  CubeRotation rotationVal;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      id = 2 - j%3;
      if (startX == endX) {
        rotationVal = {angle, 1.0, 0.0, 0.0};
        cubeFaces[id][i] = cubeStates[endX][i][j];
      }

      if (startY == endY) {
        rotationVal = {angle, 0.0, 1.0, 0.0};
        cubeFaces[id][i] = cubeStates[j][endY][i];
      }

      if (startZ == endZ) {
        rotationVal = {-1 * angle, 0.0, 0.0, 1.0};
        cubeFaces[id][i] = cubeStates[j][i][endZ];
      }

      cubeFaces[id][i].push_back(rotationVal);
    }
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (startX == endX) {
        cubeStates[endX][i][j] = cubeFaces[i][j];
      }

      if (startY == endY) {
        cubeStates[j][endY][i] = cubeFaces[i][j];
      }

      if (startZ == endZ) {
        cubeStates[j][i][endZ] = cubeFaces[i][j];
      }
    }
  }
}

GLfloat Cube::getXTranslate(int x, GLint gap) {
  return (x - 1) * cubeSize + x * gap;
}

GLfloat Cube::getYTranslate(int y, GLint gap) {
  return (y - 1) * cubeSize + y * gap;
}

GLfloat Cube::getZTranslate(int z, GLint gap) {
  return (z - 1) * cubeSize + z * gap;
}

void Cube::resetSelectedCubeFace() {
  startX = 0;
  endX = 2;
  startY = 0;
  endY = 2;
  startZ = 0;
  endZ = 2;
}

}
