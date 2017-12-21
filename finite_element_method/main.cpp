#include "Solution.h"
#include "CubeSolution.h"
#include "LinearSolution.h"

#define LEFT_POSITION		1.
#define RIGHT_POSITION		19.

#define ELEMENTS_COUNT		40

#define ELEMENT_LENGTH		(RIGHT_POSITION - LEFT_POSITION) / ELEMENTS_COUNT

int main(int argc, char* argv[])
{
	// create 2 solutions
	std::vector<Solution *> solution = {
		new LinearSolution(),
		new CubeSolution()
	};

	size_t solutionSize = solution.size();

    double x = LEFT_POSITION;

	// Create elements and add their to solutions
	for (size_t i = 0; i < ELEMENTS_COUNT + 1; i++)
	{
		// add it to every solution
		for (size_t j = 0; j < solutionSize; j++)
		{
			solution[j]->addElement(x);
		}

		// update first x-coordinate for next element
		x += ELEMENT_LENGTH;
	}

	// run application
	for (size_t i = 0; i < solutionSize; i++)
	{
		solution[i]->calc();        // calc solution
		solution[i]->save();        // save results in file
		solution[i]->report();      // report about errors
	}

	system("pause");
	return 0;
}
