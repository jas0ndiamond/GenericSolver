#include <iostream>
#include "solver/solver.h"
#include "board/board.h"

#include "solver/knightstoursolver.h"

int main() {

	std::cout << "Starting up" <<std::endl;

	Solver *s = new KnightsTourSolver(2,3);

	s->start();

	delete(s);

	return 0;
}
