#pragma once

#include "Solution.h"

class LinearSolution : public Solution
{
protected:
	const char *file = "linear";
    const char *name = "Linear";

public:
	std::vector<double> localVector(double);
	std::vector<std::vector <double>> localMatrix(double);

	const char* fileName() { return file; };
	const char* solutionName() { return name; };
};
