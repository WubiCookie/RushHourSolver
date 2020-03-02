#include "Solver.hpp"

int main()
{
	RushHourSolver::Solver s;

	while (!s.solution)
	{
		s.solve();
	}

	s.solution->retrace();
}
