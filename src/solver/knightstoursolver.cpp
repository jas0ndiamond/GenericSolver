#include "knightstoursolver.h"
#include "../board/board.h"
#include "../board/knightstourboard.h"
#include "../board/position2d.h"
#include "solver.h"

#include <vector>
#include <iostream>

// KnightsTourSolver::KnightsTourSolver(int x, int y)  {
//
//   std::cout << "KnightsTourSolver constructor" <<std::endl;
//
//   startx = x;
//   starty = y;
// }



void KnightsTourSolver::start() {

    //initialize a board and place a piece at x,y

    std::vector<std::vector<int> >* vec = new std::vector<std::vector<int> > (CHESSBOARD_SIZE, std::vector<int>(CHESSBOARD_SIZE,EMPTY_SPACE));


    //vector<int> ar = { 1, 2, 3, 4, 5 };


    // std::vector<int> row1;
    // row1.push_back(0);
    // row1.push_back(0);
    // row1.push_back(0);
    // row1.push_back(0);
    // row1.push_back(0);
    // row1.push_back(0);
    // row1.push_back(0);


    // vec->push_back( std::vector<int>(8,0) );
    // vec->push_back( std::vector<int>(8,0) );
    // vec->push_back( std::vector<int>(8,0) );
    // vec->push_back( std::vector<int>(8,0) );
    // vec->push_back( std::vector<int>(8,0) );
    // vec->push_back( std::vector<int>(8,0) );
    // vec->push_back( std::vector<int>(8,0) );
    // vec->push_back( std::vector<int>(8,0) );

    //set a value for a vector<vector<int>>*
    vec->at(startx).at(starty) = KNIGHT;



    KnightsTourBoard *startBoard = new KnightsTourBoard(vec);
    startBoard->setKnightPosition(startx, starty);

    //print the starting board
    startBoard->print();


    //call the generic solver workflow
    run(startBoard);

    delete(startBoard);
}

bool KnightsTourSolver::isNew(Board *board) {

  //check historian

  return true;
}

Position2D *KnightsTourSolver::findKnight(Board *board) {
  std::vector<std::vector<int> >::iterator xiter;

  int x =0, y;
  bool found = false;
  Position2D *pos = new Position2D(0,0);
  for(xiter = board->getBoard()->begin(); xiter < board->getBoard()->end(); xiter++)
  {
      //std::cout << "x";

      std::vector<int>::iterator yiter;

      y=0;
      for(yiter = (*xiter).begin(); yiter < (*xiter).end(); yiter++)
      {
        //std::cout <<"y";
        if( *yiter == KNIGHT ) {


          pos->setX(x);
          pos->setY(y);

          std::cout << "Knight at x: " << pos->getX() << ", y: " << pos->getY() << std::endl;

          //TODO: unsloppy break;
          //yiter = (*xiter).end();
          //xiter = board->getBoard()->end();
          found = true;
          break;
        }
        else
        {
          y++;
        }
      }

      if(found) {
        break;
      } else {
        //std::cout <<std::endl;
        x++;
      }
  }

  return pos;
}

std::vector<Board*>* KnightsTourSolver::transform(Board *board) {
  std::vector<Board*>* results = new std::vector<Board*>();

  //assume not done and new, get the possible transformations

  //find the knight's position
  //Position2D *pos = findKnight(board);

  Position2D *pos = board->getKnightPosition();

  std::cout << "Knight returned x: " << pos->getX() << ", y: " << pos->getY() << std::endl;



  //create a board for each expansion and add to results


  //cleanup
  if(pos) {
    delete(pos);
  }

  return results;
}

bool KnightsTourSolver::isDone(Board *board) {
  return false;
}
