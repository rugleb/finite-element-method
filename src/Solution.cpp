#include "Solution.h"

#include <cmath>

Solution::Solution(Element* e, std::size_t c)
{
    element = e;
    cardinality = c;

    std::size_t local_dimension = element->getLoadVector().size();
    std::size_t dimension = cardinality * (local_dimension - 1) + 1;

    load_vector = Vector(dimension, 0.);
    stiffness_matrix = Matrix(dimension, Vector(dimension, 0.));
}

double Solution::getAnalyticalSolution(double x)
{
    return -1.11 * pow(10., -9.) * exp(5. * x / 4.) + x - 6.;
}

double Solution::calculate()
{
    assembling();
    setConditions();
    solving();

    return 0.;
}

void Solution::assembling()
{
    Vector local_load_vector = element->getLoadVector();
    Matrix local_stiffness_matrix = element->getStiffnessMatrix();

    std::size_t local_dimension = local_load_vector.size();

    for (std::size_t i = 0, j = 0; i < cardinality; i++, j += local_dimension - 1) {

        for (std::size_t ii = 0; ii < local_dimension; ii++) {
            for (std::size_t jj = 0; jj < local_dimension; jj++) {

                // fill global stiffness matrix
                stiffness_matrix[j + ii][j + jj] += local_stiffness_matrix[ii][jj];
            }

            // fill global load vector
            load_vector[j + ii] += local_load_vector[ii];
        }
    }
}

void Solution::setConditions()
{
    std::size_t dimension = stiffness_matrix.size();

    // set border condition on the right end: u(19) = -10
    for (std::size_t i = 0; i < dimension; i++) {
        load_vector[i] -= stiffness_matrix[i][dimension - 1] * (-10.);
        stiffness_matrix[i][dimension - 1] = 0.;
    }

    stiffness_matrix[dimension - 1][dimension - 1] = 4.;

    // Set border condition on the left end: u(1) = -5
    for (std::size_t i = 0; i < dimension; i++) {
        load_vector[i] -= stiffness_matrix[i][0] * (-5.);
        stiffness_matrix[i][0] = 0.;
    }

    stiffness_matrix[0][0] = -4.;
}

void Solution::solving()
{
    Vector solutions = gauss(stiffness_matrix, load_vector);

    double x = 1.;
    int i = 0;

    while (x < 19.) {

        printf("%3.3f %3.3f %3.3f\n", solutions[i], getAnalyticalSolution(x), x);

        x += element->getLength();
        i += element->getLoadVector().size() - 1;
    }

}
