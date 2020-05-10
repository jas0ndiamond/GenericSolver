#include "knightstourboard.h"
#include "board.h"
#include "position2d.h"

#include <vector>

KnightsTourBoard::KnightsTourBoard(std::vector<std::vector<int> > *startBoard) : Board(startBoard)
{
  steps = 0;
  knightPosition = new Position2D(0,0);
}

KnightsTourBoard::KnightsTourBoard(std::vector<std::vector<int> > *startBoard, std::vector<std::vector<int> > *parent) : Board(startBoard, parent) {
  steps = 0;
  knightPosition = new Position2D(0,0);
};

KnightsTourBoard::~KnightsTourBoard() {
  if(knightPosition) {
    delete(knightPosition);
  }
}

void KnightsTourBoard::setSteps(int steps) {
  this->steps = steps;
}

int KnightsTourBoard::getSteps() {
  return steps;
}

void KnightsTourBoard::setKnightPosition(int x, int y) {
  knightPosition->setX(x);
  knightPosition->setY(y);
}

Position2D* KnightsTourBoard::getKnightPosition() {
  return knightPosition;
}


int KnightsTourBoard::hashcode() {
  return 0;
}

void KnightsTourBoard::print() {

}
