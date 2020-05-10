#include <vector>

#include "../board/board.h"
#include "../board/position2d.h"
#include "solver.h"


#ifndef KNIGHTSTOUR_H
#define KNIGHTSTOUR_H

class KnightsTourSolver : public Solver {

private:
  int startx;
  int starty;

  const int CHESSBOARD_SIZE = 8;
  const int EMPTY_SPACE = 0;
  const int KNIGHT = 99;

public:

  KnightsTourSolver(int x, int y) : startx(x), starty(y) {};

  Position2D *findKnight(Board *board);

  virtual void start();

  virtual bool isNew(Board *board);

  virtual std::vector<Board*>* transform(Board *board);

  virtual bool isDone(Board *board);
};

#endif
