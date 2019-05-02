#ifndef SOLUTION_H
#define SOLUTION_H


#include "Element.h"


class Solution {
protected:
    Element* element;
    std::size_t cardinality;

    Vector load_vector;
    Matrix stiffness_matrix;

    void assembling();
    void setConditions();
    void solving();

public:
    explicit Solution(Element* e, std::size_t c);

    static double getAnalyticalSolution(double x);

    double calculate();
};


#endif
