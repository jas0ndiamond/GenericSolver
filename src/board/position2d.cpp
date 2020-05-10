#include "position2d.h"

Position2D::Position2D(int x, int y) {
  xPos = x;
  yPos = y;
}

int Position2D::getX() {
  return xPos;
}

int Position2D::getY() {
  return yPos;
}

void Position2D::setX(int x) {
  xPos = x;
}

void Position2D::setY(int y) {
  yPos = y;
}
