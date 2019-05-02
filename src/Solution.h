#ifndef SOLUTION_H
#define SOLUTION_H


#include "Element.h"


class Solution {
protected:
    Vector load_vector;
    Matrix stiffness_matrix;
public:
    explicit Solution();
};


#endif
