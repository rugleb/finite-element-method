#include "LinearSolution.h"

std::vector<std::vector<double>> LinearSolution::localMatrix(double l)
{
    // original matrix
	std::vector<std::vector<double>> matrix = {
		{
			5. / 2. - 4. / l,
			4. / l  - 5. / 2
		},
		{
			4. / l + 5. / 2.,
			-4. / l - 5. / 2.
		}
	};

	return matrix;
}

std::vector<double> LinearSolution::localVector(double l)
{
    // original vector
	std::vector<double> vector = {
		-5. * l / 2.,
		-5. * l / 2.
	};

	return vector;
}
