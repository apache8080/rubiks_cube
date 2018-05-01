#include <GL/gl.h>
#include <GL/glut.h>
#include <vector>

using namespace std;

struct CubeRotation {
  GLfloat angle, x, y, z;
};

GLfloat angle, fAspect, cube_size;
GLint rot_x, rot_y, crement, x_0, x_k, y_0, y_k, z_0, z_k, gap, gap_crement;

vector<CubeRotation> cubeStates[3][3][3];

void loadVisualParams();

void rotateCube(GLfloat angle) {
  vector<CubeRotation> cubeFaces[3][3];
  int id;
  CubeRotation rotationVal;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      id = 2 - j%3;
      if (x_0 == x_k) {
        rotationVal = {angle, 1.0, 0.0, 0.0};
        cubeFaces[id][i] = cubeStates[x_k][i][j];
      }

      if (y_0 == y_k) {
        rotationVal = {angle, 0.0, 1.0, 0.0};
        cubeFaces[id][i] = cubeStates[j][y_k][i];
      }

      if (z_0 == z_k) {
        rotationVal = {-1 * angle, 0.0, 0.0, 1.0};
        cubeFaces[id][i] = cubeStates[j][i][z_k];
      }

      cubeFaces[id][i].push_back(rotationVal);
    }
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (x_0 == x_k) {
        cubeStates[x_k][i][j] = cubeFaces[i][j];
      }

      if (y_0 == y_k) {
        cubeStates[j][y_k][i] = cubeFaces[i][j];
      }

      if (z_0 == z_k) {
        cubeStates[j][i][z_k] = cubeFaces[i][j];
      }
    }
  }
}

void resetSelectedCubeFace() {
  x_0 = 0;
  x_k = 2;
  y_0 = 0;
  y_k = 2;
  z_0 = 0;
  z_k = 2;
}

void setCameraCoords() {
  gluLookAt(0, 80, 200, 0, 0, 0, 0, 1, 0);
}

void drawCube(int x, int y, int z) {
  vector<CubeRotation> lrot = cubeStates[x][y][z];

  glPushMatrix();

  glTranslatef((x - 1) * cube_size + x * gap, (y - 1) * cube_size + y * gap, (z - 1) * cube_size + z * gap);

  for (int i = lrot.size() - 1; i >= 0; i--) {
    glRotatef(lrot[i].angle, lrot[i].x, lrot[i].y, lrot[i].z);
  }

  //  front face
  glColor3f(1.0, 0.0, 0.0);
  glBegin(GL_QUADS);
    glNormal3f(0.0, 0.0, 1.0);
    glVertex3f(cube_size/2, cube_size/2, cube_size/2);
    glVertex3f(-cube_size/2, cube_size/2, cube_size/2);
    glVertex3f(-cube_size/2, -cube_size/2, cube_size/2);
    glVertex3f(cube_size/2, -cube_size/2, cube_size/2);
  glEnd();

  //  back face
  glColor3f(1.0, 0.5, 0.0);
  glBegin(GL_QUADS);
    glNormal3f(0.0, 0.0, -1.0);
    glVertex3f(cube_size/2, cube_size/2, -cube_size/2);
    glVertex3f(cube_size/2, -cube_size/2, -cube_size/2);
    glVertex3f(-cube_size/2, -cube_size/2, -cube_size/2);
    glVertex3f(-cube_size/2, cube_size/2, -cube_size/2);
  glEnd();

  //  left face
  glColor3f(0.0, 0.0, 1.0);
  glBegin(GL_QUADS);
    glNormal3f(-1.0, 0.0, 0.0);
    glVertex3f(-cube_size/2, cube_size/2, cube_size/2);
    glVertex3f(-cube_size/2, cube_size/2, -cube_size/2);
    glVertex3f(-cube_size/2, -cube_size/2, -cube_size/2);
    glVertex3f(-cube_size/2, -cube_size/2, cube_size/2);
  glEnd();

  //  right face
  glColor3f(0.0, 1.0, 0.0);
  glBegin(GL_QUADS);
    glNormal3f(1.0, 0.0, 0.0);
    glVertex3f(cube_size/2, cube_size/2, cube_size/2);
    glVertex3f(cube_size/2, -cube_size/2, cube_size/2);
    glVertex3f(cube_size/2, -cube_size/2, -cube_size/2);
    glVertex3f(cube_size/2, cube_size/2, -cube_size/2);
  glEnd();

  //  top face
  glColor3f(1.0, 1.0, 1.0);
  glBegin(GL_QUADS);
    glNormal3f(0.0, 1.0, 0.0);
    glVertex3f(-cube_size/2, cube_size/2, -cube_size/2);
    glVertex3f(-cube_size/2, cube_size/2, cube_size/2);
    glVertex3f(cube_size/2, cube_size/2, cube_size/2);
    glVertex3f(cube_size/2, cube_size/2, -cube_size/2);
  glEnd();

  //  bottom face
  glColor3f(1.0, 1.0, 0.0);
  glBegin(GL_QUADS);
    glNormal3f(0.0, -1.0, 0.0);
    glVertex3f(-cube_size/2, -cube_size/2, -cube_size/2);
    glVertex3f(cube_size/2, -cube_size/2, -cube_size/2);
    glVertex3f(cube_size/2, -cube_size/2, cube_size/2);
    glVertex3f(-cube_size/2, -cube_size/2, cube_size/2);
  glEnd();

  glPopMatrix();
}


void draw() {
  int x = -cube_size, y = -cube_size, z = -cube_size;

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glLoadIdentity();

  setCameraCoords();

  glRotatef(rot_x, 1.0, 0.0, 0.0);
  glRotatef(rot_y, 0.0, 1.0, 0.0);

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
  cube_size = 30.0;
  rot_x = 0.0;
  rot_y = 0.0;
  crement = 5;
  gap = 5;
  gap_crement = 3;

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

  angle = 45;
}

void loadVisualParams() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluPerspective(angle, fAspect, 0.4, 500);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  setCameraCoords();
}

void reshapeWindow(GLsizei w, GLsizei h) {
  if (h == 0) {
    h = 1;
  }

  glViewport(0, 0, w, h);

  fAspect = (GLfloat)(w) / (GLfloat)(h);

  loadVisualParams();
}

void controls(unsigned char key, int x, int y) {
  switch (key) {
    case '+':
      gap += gap_crement;
      break;

    case '-':
      gap -= gap_crement;
      break;

    case 'l':
      rot_y = (rot_y - crement) % 360;
      break;

    case 'j':
      rot_y = (rot_y + crement) % 360;
      break;

    case 'i':
      rot_x = (rot_x + crement) % 360;
      break;

    case 'k':
      rot_x = (rot_x - crement) % 360;
      break;

    case 'q':
      resetSelectedCubeFace();
      x_0 = 0;
      x_k = 0;
      break;

    case 'w':
      resetSelectedCubeFace();
      x_0 = 1;
      x_k = 1;
      break;

    case 'e':
      resetSelectedCubeFace();
      x_0 = 2;
      x_k = 2;
      break;

    case 'a':
      resetSelectedCubeFace();
      y_0 = 0;
      y_k = 0;
      break;

    case 's':
      resetSelectedCubeFace();
      y_0 = 1;
      y_k = 1;
      break;

    case 'd':
      resetSelectedCubeFace();
      y_0 = 2;
      y_k = 2;
      break;

    case 'c':
      resetSelectedCubeFace();
      z_0 = 0;
      z_k = 0;
      break;

    case 'x':
      resetSelectedCubeFace();
      z_0 = 1;
      z_k = 1;
      break;

    case 'z':
      resetSelectedCubeFace();
      z_0 = 2;
      z_k = 2;
      break;

    case 'u':
      rotateCube(-90);
      break;

    case 'o':
      rotateCube(90);
      break;

    default:
      break;
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
