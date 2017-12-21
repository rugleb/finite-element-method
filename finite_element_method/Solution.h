#pragma once

#include <vector>

#define LEFT_CONDITION     -5.
#define RIGHT_CONDITION    -10.

#define DEFAULT_VALUE	   0.

class Solution
{
protected:
	double delta;
	double epsilon;

    const char *file = "__basic";
	const char *name = "__Basic";

	std::vector<double> vector;
	std::vector<double> solutions;
	std::vector<double> coordinates;

	std::vector<std::vector <double>> matrix;

public:
	Solution();
	~Solution();

	void calc();
	void save();
	void report();
	void assembling();
	void initMatrix();
	void gaussSolver();
	void errorAnalysis();
	void addElement(double);
	void setFileName(const char *);

	void print();
	void printMatrix();
	void printVector();
	void printSolutions();

	void clearMatrix();
	void clearVector();
	void clearSolutions();
	void clearCoordinates();

	virtual void setConditions();
	virtual void updateSolution();
	virtual const char* fileName() = 0;
	virtual const char* solutionName() = 0;
	virtual std::vector<double> localVector(double) = 0;
	virtual std::vector<std::vector <double>> localMatrix(double) = 0;

	int elementsCount();
	int localMatrixSize();
	
	virtual double analyticSolution(double);
};
