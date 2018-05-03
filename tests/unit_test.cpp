// Tests
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../src/objects/cube.h"

using objects::Cube;

TEST_CASE("Setting and Getting Cube Size") {
  Cube c;
  c.setCubeSize(30.0);

  REQUIRE(c.getCubeSize() == 30.0);
}

TEST_CASE("Setting and Getting X Rotation") {
  Cube c;
  c.setXRotation(1);

  REQUIRE(c.getXRotation() == 1);
}

TEST_CASE("Setting and Getting Y Rotation") {
  Cube c;
  c.setYRotation(1);

  REQUIRE(c.getYRotation() == 1);
}

TEST_CASE("Rotating X Test") {
  Cube c;
  c.setXRotation(1);
  c.setRotationIncrement(5);

  c.rotateX(1);
  REQUIRE(c.getXRotation() == 6);

  c.rotateX(-1);
  REQUIRE(c.getXRotation() == 355);
}

TEST_CASE("Rotating Y Test") {
  Cube c;
  c.setYRotation(1);
  c.setRotationIncrement(5);

  c.rotateY(1);
  REQUIRE(c.getYRotation() == 6);

  c.rotateY(-1);
  REQUIRE(c.getYRotation() == 355);
}

TEST_CASE("Translate X Test") {
  Cube c;
  c.setCubeSize(30.0);

  REQUIRE(c.getXTranslate(2, 5) == 40.0);
}

TEST_CASE("Translate Y Test") {
  Cube c;
  c.setCubeSize(30.0);

  REQUIRE(c.getYTranslate(2, 5) == 40.0);
}

TEST_CASE("Translate Z Test") {
  Cube c;
  c.setCubeSize(30.0);

  REQUIRE(c.getZTranslate(2, 5) == 40.0);
}
