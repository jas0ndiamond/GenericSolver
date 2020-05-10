#include <iostream>
#include <string>

#include "board.h"

/**
 *  Build a board full of zeros
 *
 */
// Board::Board() {
//
// }



Board::Board(std::vector<std::vector<int> > *startBoard) {
  board = startBoard;
  parentBoard = NULL;
}

Board::Board(std::vector<std::vector<int> > *startBoard, std::vector<std::vector<int> > *parent) {
  board = startBoard;
  parentBoard = parent;
}

Board::~Board() {
  if(board)
  {
    board->clear();
    delete(board);
  }

  if(parentBoard)
  {
    parentBoard->clear();
    delete(parentBoard);
  }
}



void Board::set(int x, int y, int value) {
  // if(x >= 0 && x < board->size()) {
  //   if(y >= 0 && y < board[x].size() )
  //   {
  //     board[x][y] = value;
  //   }
  // }
}

int Board::getAt(int x, int y) {
  return -1;
}

std::vector<std::vector<int> > * Board::getBoard() {
  return board;
}

std::vector<std::vector<int> > * Board::getParentBoard() {
  return parentBoard;
}

void Board::print() {
  std::vector<std::vector<int> >::iterator xiter;
  std::vector<int>::iterator yiter;

  std::cout << "----------------" <<std::endl;
  for(xiter = getBoard()->begin(); xiter < getBoard()->end(); xiter++)
  {
      //std::cout << "x";

      std::cout << "|";
      for(yiter = (*xiter).begin(); yiter < (*xiter).end(); yiter++)
      {
        //std::cout <<"y";
        std::cout << *yiter << "|" ;
      }

      std::cout << std::endl << "----------------" <<std::endl;
  }
}
