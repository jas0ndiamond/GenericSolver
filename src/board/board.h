#include <vector>

#ifndef BOARD_H
#define BOARD_H

class Board {
protected:
  std::vector<std::vector<int> > *board;
  std::vector<std::vector<int> > *parentBoard;
public:
  //Board();
  ~Board();

  Board(std::vector<std::vector<int> > * startBoard);
  Board(std::vector<std::vector<int> > *startBoard, std::vector<std::vector<int> > *parent);

  void set(int x, int y, int value);

  int getAt(int x, int y);

  std::vector<std::vector<int> > * getBoard();

  std::vector<std::vector<int> > * getParentBoard();

  int hashcode();

  void print();
};

#endif
