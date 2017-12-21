#include "Solution.h"

#include <fstream>
#include <iostream>
#include <filesystem>

Solution::Solution()
{
	this->epsilon = this->delta = 0.;
}

Solution::~Solution()
{
	// clear vectors vector
	clearVector();

	// clear matrix vector
	clearMatrix();

	// clear solutions
	clearSolutions();

	// clear coordinates vector
	clearCoordinates();
}

void Solution::setFileName(const char * fileName)
{
	file = fileName;
}

void Solution::addElement(double x)
{
    // x - start coordinate of element
	this->coordinates.push_back(x);
}

int Solution::elementsCount()
{
	 return coordinates.size() - 1;
}

int Solution::localMatrixSize()
{
	return localMatrix(0.).size();
}

double Solution::analyticSolution(double x)
{
	return -1.11 * pow(10, -9) * exp(5 * x / 4) + x - 6;
}

void Solution::calc()
{
	this->initMatrix();		       // init all matrix
	this->assembling();            // start assembling to global size
	this->setConditions();         // set conditions
	this->gaussSolver();           // run Gauss method
	this->updateSolution();        // postprocessing
	this->errorAnalysis();         // analysis error
}

void Solution::initMatrix()
{
	// init global matrix size
	int matrixSize = elementsCount() * (localMatrixSize() - 1) + 1;

	// set default values (zeros)
	for (size_t i = 0; i < matrixSize; i++)
	{
		// global matrix
		std::vector<double> row;
		for (size_t j = 0; j < matrixSize; j++)
		{
			row.push_back(DEFAULT_VALUE);
		}
		matrix.push_back(row);

		// global vector
		vector.push_back(DEFAULT_VALUE);

		// solutions
		solutions.push_back(DEFAULT_VALUE);
	}
}

void Solution::assembling()
{
	int localPosition = 0;                            // first position for local matrix
	int localMatrixSize = this->localMatrixSize();    // count elements on local matrix row
	
	for (size_t i = 0; i < elementsCount(); i++)
	{
		// element length
		double length = coordinates[i + 1] - coordinates[i];

		std::vector<std::vector<double>> localMatrix = this->localMatrix(length);		// local matrix
		std::vector<double> localVector = this->localVector(length);					// local vector

		// run assembling
		for (size_t row = 0; row < localMatrixSize; row++)
		{
			for (size_t column = 0; column < localMatrixSize; column++)
			{
				// create global matrix
				matrix[localPosition + row][localPosition + column] += localMatrix[row][column];
			}
			// create global vector
			vector[localPosition + row] += localVector[row];
		}

		localPosition += localMatrixSize - 1;
	}
}

void Solution::setConditions()
{
	size_t matrixSize = matrix.size();

	// Set border condition on the right end
	// u(19) = -10
	for (size_t i = 0; i < matrixSize; i++)
	{
		vector[i] -= matrix[i][matrixSize - 1] * (RIGHT_CONDITION);
		matrix[i][matrixSize - 1] = 0.;
	}
	matrix[matrixSize - 1][matrixSize - 1] = 4.;

	// Set border condition on the left end
	// u(1) = -5
	for (size_t i = 0; i < matrixSize; i++)
	{
		vector[i] -= matrix[i][0] * (LEFT_CONDITION);
		matrix[i][0] = 0.;
	}
	matrix[0][0] = -4.;
}

void Solution::gaussSolver()
{
	int matrixSize = matrix.size();

	double tmp;

	for (int row = 0; row < matrixSize; row++)
	{
		for (int i = 0; i < row; i++)
		{
			tmp = matrix[row][i];
			vector[row] -= tmp * vector[i];

			if (!tmp) continue;

			for (int j = 0; j < matrixSize; j++)
			{
				matrix[row][j] -= tmp * matrix[i][j];
			}
		}

		tmp = matrix[row][row];
		for (int j = row; j < matrixSize; j++)
		{
			matrix[row][j] /= tmp;
		}
		vector[row] /= tmp;
	}

	for (int i = matrixSize - 1; i > -1; i--)
	{
		for (int j = matrixSize - 1; j > i; j--)
		{
			vector[i] -= matrix[i][j] * solutions[j];
		}
		solutions[i] = vector[i];
	}

}

void Solution::updateSolution()
{
	this->solutions.back() = RIGHT_CONDITION;
	this->solutions.front() = LEFT_CONDITION;

	std::vector<double> compressedSolutions;

	for (size_t i = 0; i < this->solutions.size(); i += localMatrixSize() - 1)
	{
		compressedSolutions.push_back(this->solutions[i]);
	}

	this->solutions = compressedSolutions;
}

void Solution::errorAnalysis()
{
	std::ofstream fout("analytic");

	for (size_t i = 0; i < coordinates.size(); i++)
	{
		// calc analytic solution
		double analytic = analyticSolution(coordinates[i]);

		// save result in file
		fout << coordinates[i] << "\t" << analytic << std::endl;

		// find max errors
		double _delta = fabs(solutions[i] - analytic);
		double _epsilon = fabs((solutions[i] - analytic) / analytic);

		if (this->delta < _delta)
		{
			this->delta = _delta;
		}

		if (this->epsilon < _epsilon)
		{
			this->epsilon = _epsilon;
		}

	}

	fout.close();
}

void Solution::report()
{
	std::cout << solutionName() << " solution." << std::endl;
	std::cout << "---- max delta: " << this->delta << std::endl;
	std::cout << "---- max epsilon: " << this->epsilon << std::endl;
	std::cout << std::endl;
}

void Solution::save()
{
	std::ofstream fout(fileName());

	for (int i = 0; i < solutions.size(); i++)
	{
		fout << coordinates[i] << "\t" << solutions[i] << std::endl;
	}

	fout.close();
}

void Solution::print()
{
	printMatrix();
	printVector();
	printSolutions();
}

void Solution::printMatrix()
{
	std::cout << "Global matrix: " << std::endl;
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
		{
			std::cout << matrix[i][j] << ' ';;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;	
}

void Solution::printVector()
{
	std::cout << "Global vector: " << std::endl;
	for (int i = 0; i < vector.size(); i++)
	{
		std::cout << vector[i] << std::endl;
	}
	std::cout << std::endl;
}

void Solution::printSolutions()
{
	std::cout << "Solutions: " << std::endl;
	for (int i = 0; i < solutions.size(); i++)
	{
		std::cout << solutions[i] << std::endl;
	}
	std::cout << std::endl;	
}

void Solution::clearMatrix()
{
	for (size_t i = 0; i < matrix.size(); i++)
	{
		matrix[i].clear();
	}

	matrix.clear();
}

void Solution::clearVector()
{
	vector.clear();
}

void Solution::clearSolutions()
{
	solutions.clear();
}

void Solution::clearCoordinates()
{
	coordinates.clear();
}

