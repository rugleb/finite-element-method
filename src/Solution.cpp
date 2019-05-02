#include "Solution.h"

#include <cmath>

Solution::Solution()
{
    load_vector = Vector(0, 0.);
    stiffness_matrix = Matrix(0, Vector(0, 0.));
}

double Solution::getAnalyticalSolution(double x)
{
    return -1.11 * pow(10., -9.) * exp(5. * x / 4.) + x - 6.;
}
