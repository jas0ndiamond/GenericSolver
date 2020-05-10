#include "../board/board.h"

#include <queue>

#ifndef SOLVER_H
#define SOLVER_H

class Solver {

private:
  bool shouldQuit;
  bool isFinished;
  std::queue<Board*> *workQueue;

  const int INITIAL_QUEUE_SIZE = 100;

public:
  Solver() : shouldQuit(false), isFinished(false)
  {
    workQueue = new std::queue<Board*>;
  };

  ~Solver();

  void quit();

  void run(Board *startingBoard);

  virtual void start() = 0;

protected:
  virtual bool isNew(Board *board) = 0;

  virtual std::vector<Board*>* transform(Board *board) = 0;

  virtual bool isDone(Board *board) = 0;

};

#endif
