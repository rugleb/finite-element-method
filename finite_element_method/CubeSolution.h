#pragma once

#include "Solution.h"

class CubeSolution : public Solution
{
protected:
	const char *file = "cube";
	const char *name = "Cube";

public:
	std::vector<double> localVector(double);
	std::vector<std::vector <double>> localMatrix(double);

	const char* fileName() { return file; };
	const char* solutionName() { return name; };
};
