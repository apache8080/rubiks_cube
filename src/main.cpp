#include <GL/gl.h>
#include <GL/glut.h>
#include <vector>
#include "objects/cube.h"
#include "utils/camera.h"
#include "utils/controller.h"

using namespace std;
using objects::Cube;
using utils::Camera;
using utils::Controller;

Cube rubiks;
Camera cam;

void loadVisualParams();

void setCameraCoords() {
  gluLookAt(Camera::eyeX, Camera::eyeY, Camera::eyeZ,
            Camera::centerX, Camera::centerY, Camera::centerZ,
            Camera::upX, Camera::upY, Camera::upZ);
}

void drawCube(int x, int y, int z) {
  vector<Cube::CubeRotation> lrot = rubiks.cubeStates[x][y][z];

  glPushMatrix();

  glTranslatef(rubiks.getXTranslate(x, cam.getGap()),
               rubiks.getYTranslate(y, cam.getGap()),
               rubiks.getZTranslate(z, cam.getGap()));

  for (int i = lrot.size() - 1; i >= 0; i--) {
    glRotatef(lrot[i].angle, lrot[i].x, lrot[i].y, lrot[i].z);
  }

  GLfloat cubeSize = rubiks.getCubeSize();

  //  front face
  glColor3f(1.0, 0.0, 0.0);
  glBegin(GL_QUADS);
    glNormal3f(0.0, 0.0, 1.0);
    glVertex3f(cubeSize/2, cubeSize/2, cubeSize/2);
    glVertex3f(-cubeSize/2, cubeSize/2, cubeSize/2);
    glVertex3f(-cubeSize/2, -cubeSize/2, cubeSize/2);
    glVertex3f(cubeSize/2, -cubeSize/2, cubeSize/2);
  glEnd();

  //  back face
  glColor3f(1.0, 0.5, 0.0);
  glBegin(GL_QUADS);
    glNormal3f(0.0, 0.0, -1.0);
    glVertex3f(cubeSize/2, cubeSize/2, -cubeSize/2);
    glVertex3f(cubeSize/2, -cubeSize/2, -cubeSize/2);
    glVertex3f(-cubeSize/2, -cubeSize/2, -cubeSize/2);
    glVertex3f(-cubeSize/2, cubeSize/2, -cubeSize/2);
  glEnd();

  //  left face
  glColor3f(0.0, 0.0, 1.0);
  glBegin(GL_QUADS);
    glNormal3f(-1.0, 0.0, 0.0);
    glVertex3f(-cubeSize/2, cubeSize/2, cubeSize/2);
    glVertex3f(-cubeSize/2, cubeSize/2, -cubeSize/2);
    glVertex3f(-cubeSize/2, -cubeSize/2, -cubeSize/2);
    glVertex3f(-cubeSize/2, -cubeSize/2, cubeSize/2);
  glEnd();

  //  right face
  glColor3f(0.0, 1.0, 0.0);
  glBegin(GL_QUADS);
    glNormal3f(1.0, 0.0, 0.0);
    glVertex3f(cubeSize/2, cubeSize/2, cubeSize/2);
    glVertex3f(cubeSize/2, -cubeSize/2, cubeSize/2);
    glVertex3f(cubeSize/2, -cubeSize/2, -cubeSize/2);
    glVertex3f(cubeSize/2, cubeSize/2, -cubeSize/2);
  glEnd();

  //  top face
  glColor3f(1.0, 1.0, 1.0);
  glBegin(GL_QUADS);
    glNormal3f(0.0, 1.0, 0.0);
    glVertex3f(-cubeSize/2, cubeSize/2, -cubeSize/2);
    glVertex3f(-cubeSize/2, cubeSize/2, cubeSize/2);
    glVertex3f(cubeSize/2, cubeSize/2, cubeSize/2);
    glVertex3f(cubeSize/2, cubeSize/2, -cubeSize/2);
  glEnd();

  //  bottom face
  glColor3f(1.0, 1.0, 0.0);
  glBegin(GL_QUADS);
    glNormal3f(0.0, -1.0, 0.0);
    glVertex3f(-cubeSize/2, -cubeSize/2, -cubeSize/2);
    glVertex3f(cubeSize/2, -cubeSize/2, -cubeSize/2);
    glVertex3f(cubeSize/2, -cubeSize/2, cubeSize/2);
    glVertex3f(-cubeSize/2, -cubeSize/2, cubeSize/2);
  glEnd();

  glPopMatrix();
}


void draw() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glLoadIdentity();

  setCameraCoords();

  glRotatef(rubiks.getXRotation(), 1.0, 0.0, 0.0);
  glRotatef(rubiks.getYRotation(), 0.0, 1.0, 0.0);

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < 3; ++k) {
        drawCube(i, j, k);
      }
    }
  }

  glutSwapBuffers();
}

void init() { 
  rubiks.setCubeSize(30.0);
  rubiks.setXRotation(0.0);
  rubiks.setYRotation(0.0);
  rubiks.setRotationIncrement(5);

  cam.setGap(5);
  cam.setGapIncrement(3);

  GLfloat ambient_lighte[4] = {0.2, 0.2, 0.2, 1.0};
  GLfloat diffuse_light[4] = {0.7, 0.7, 0.7, 1.0};
  GLfloat specular_light[4]={1.0, 1.0, 1.0, 1.0};
  GLfloat light_position[4]={0.0, 50.0, 50.0, 1.0};

  GLfloat specularity[4] = {1.0, 1.0, 1.0, 1.0};
  GLint material_specularity = 60;

  glClearColor(0.0, 0.0, 0.0, 1.0);

  glShadeModel(GL_SMOOTH);

  glMaterialfv(GL_FRONT, GL_SPECULAR, specularity);

  glMateriali(GL_FRONT, GL_SHININESS, material_specularity);

  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient_lighte);

  glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_lighte);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
  glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);

  glEnable(GL_COLOR_MATERIAL);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_DEPTH_TEST);

  cam.setAngle(45);
}

void loadVisualParams() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluPerspective(cam.getAngle(), cam.getFAspect(), 0.4, 500);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  setCameraCoords();
}

void reshapeWindow(GLsizei w, GLsizei h) {
  if (h == 0) {
    h = 1;
  }

  glViewport(0, 0, w, h);

  cam.setFAspect((GLfloat) w, (GLfloat) h);

  loadVisualParams();
}

void controls(unsigned char key, int x, int y) {
  if (key == Controller::ZOOM_IN_KEY) {
      cam.zoomOut();
  } else if (key == Controller::ZOOM_OUT_KEY) {
      cam.zoomIn();
  } else if (key == Controller::RIGHT_ARROW_KEY) {
      rubiks.rotateY(1);
  } else if (key == Controller::LEFT_ARROW_KEY) {
      rubiks.rotateY(-1);
  } else if (key == Controller::UP_ARROW_KEY) {
      rubiks.rotateX(-1);
  } else if (key == Controller::DOWN_ARROW_KEY) {
      rubiks.rotateX(1);
  } else if (key == Controller::X_LAYER1_KEY) {
      rubiks.resetSelectedCubeFace();
      rubiks.selectCubeFaceX(0, 0);
  } else if (key == Controller::X_LAYER2_KEY) {
      rubiks.resetSelectedCubeFace();
      rubiks.selectCubeFaceX(1, 1);
  } else if (key == Controller::X_LAYER3_KEY) {
      rubiks.resetSelectedCubeFace();
      rubiks.selectCubeFaceX(2, 2);
  } else if (key == Controller::Y_LAYER1_KEY) {
      rubiks.resetSelectedCubeFace();
      rubiks.selectCubeFaceY(0, 0);
  } else if (key == Controller::Y_LAYER2_KEY) {
      rubiks.resetSelectedCubeFace();
      rubiks.selectCubeFaceY(1, 1);
  } else if (key == Controller::Y_LAYER3_KEY) {
      rubiks.resetSelectedCubeFace();
      rubiks.selectCubeFaceY(2, 2);
  } else if (key == Controller::Z_LAYER1_KEY) {
      rubiks.resetSelectedCubeFace();
      rubiks.selectCubeFaceZ(0, 0);
  } else if (key == Controller::Z_LAYER2_KEY) {
      rubiks.resetSelectedCubeFace();
      rubiks.selectCubeFaceZ(1, 1);
  } else if (key == Controller::Z_LAYER3_KEY) {
      rubiks.resetSelectedCubeFace();
      rubiks.selectCubeFaceZ(2, 2);
  } else if (key == Controller::COUNTER_CLOCKWISE_KEY) {
      rubiks.rotateSelectedCubeFace(-90);
  } else if (key == Controller::CLOCKWISE_KEY) {
      rubiks.rotateSelectedCubeFace(90);
  }

  glutPostRedisplay();
}


int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(400, 400);
  glutCreateWindow("Rubik's Cube");
  glutDisplayFunc(draw);
  glutReshapeFunc(reshapeWindow);
  glutKeyboardFunc(controls);
  init();
  glutMainLoop();
}
