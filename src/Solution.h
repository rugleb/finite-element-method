#ifndef SOLUTION_H
#define SOLUTION_H


#include "Element.h"


class Solution {
protected:
    Element* element;
    std::size_t elementsCount;

    Vector solution;
    Vector load_vector;
    Matrix stiffness_matrix;

    void assembling();
    void setConditions();
    void solve();

public:
    explicit Solution(Element* e, std::size_t elementsCount);

    static double getAnalyticalSolution(double x);

    void calculate();
    void analyse(double x);
};


#endif
