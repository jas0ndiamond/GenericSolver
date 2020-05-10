#include "solver.h"
#include <iostream>

// Solver::Solver() {
//
// }

Solver::~Solver() {
  if(workQueue) {
    while(!workQueue->empty()) {
      delete(workQueue->front());
      workQueue->pop();
    }

    delete(workQueue);
  }
}

void Solver::quit() {
  shouldQuit = true;
}

void Solver::run(Board *startingBoard) {
  int debug_stop = 100;
  int iterations = 0;

  //add the starting board to the work queue
  workQueue->push(startingBoard);

  while( !workQueue->empty() && !shouldQuit ) {

    std::cout << "Running iteration " << iterations << std::endl;

    //get the next set of boards from the queue, and order this subqueue for transformation

    Board *thisBoard = workQueue->front();
    workQueue->pop();

    std::cout << "Got board from work queue:"<< std::endl;
    thisBoard->print();

    if(!thisBoard) {
      std::cout << "Got a null board from the work queue" <<std::endl;
    }

    //invoke call to transform board, add results back to the queue

    std::vector<Board*>* newBoards = transform(thisBoard);

    std::cout <<"Transformation yielded new boards: " << newBoards->size() << std::endl;

    //are any of the new boards the solution we're looking for?

    while( !newBoards->empty() ) {

      if(!newBoards->back()) {
          std::cout << "Got a null board from the transformation" << std::endl;
          //delete(newBoards->back());
          newBoards->pop_back();
          continue;
      }

      if(!isNew(newBoards->back())){
        //old board, don't care
      }
      else {
        //new board

        //is it a solution?
        if(!isDone(newBoards->back())) {
          //no, but it's new so add it to the work queue
          workQueue->push(newBoards->back());
          newBoards->pop_back();
        }
        else {
          //done! build the solution report and break the outer loop
          std::cout << "Found a solution! " << std::endl;
          newBoards->back()->print();


          isFinished = true;

          //destroy the rest of the new boards
          while( !newBoards->empty() ) {
            delete(newBoards->back());
            newBoards->pop_back();
          }

          break;
        }
      }

    }

    //delete the new boards vector
    if(newBoards) {
      delete(newBoards);
    }



    if(isFinished) {
      //solution found
      std::cout << "A solution was found" << std::endl;
      break;
    } else {
      //no solution found. work queue exhausted or quit externally
      std::cout << "No solution was found" << std::endl;
      break;
    }


    if(iterations > debug_stop ) {
      std::cout << "Debug stop exiting" << std::endl;
      break;
    }

    iterations++;
  }


}
