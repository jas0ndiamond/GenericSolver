#include "board.h"
#include "position2d.h"

#include <vector>

#ifndef KNIGHTS_TOUR_BOARD_H
#define KNIGHTS_TOUR_BOARD_H

class KnightsTourBoard : public Board {
private:
  int steps;
  Position2D *knightPosition;
public:

  KnightsTourBoard(std::vector<std::vector<int> > * startBoard);
  KnightsTourBoard(std::vector<std::vector<int> > *startBoard, std::vector<std::vector<int> > *parent);

  ~KnightsTourBoard();

  void setSteps(int steps);
  int getSteps();

  void setKnightPosition(int x, int y);
  Position2D* getKnightPosition();


  int hashcode();

  void print();
};

#endif
