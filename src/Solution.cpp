#include "Solution.h"

#include <cmath>

Solution::Solution(Element* e, std::size_t elements)
{
    element = e;
    elementsCount = elements;

    auto size = elementsCount * (e->getDimension() - 1) + 1;

    solution = Vector(size, 0.);
    load_vector = Vector(size, 0.);
    stiffness_matrix = Matrix(size, Vector(size, 0.));
}

double Solution::getAnalyticalSolution(double x)
{
    return -1.11 * pow(10., -9.) * exp(5. * x / 4.) + x - 6.;
}

double Solution::calculate()
{
    assembling();
    setConditions();
    solve();

    return 0.;
}

void Solution::assembling()
{
    Vector local_load_vector = element->getLoadVector();
    Matrix local_stiffness_matrix = element->getStiffnessMatrix();

    std::size_t local_dimension = element->getDimension();

    for (std::size_t i = 0, j = 0; i < elementsCount; i++, j += local_dimension - 1) {

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
    // set border condition on the right end: u(19) = -10
    for (std::size_t i = 0; i < load_vector.size(); i++) {
        load_vector[i] -= -10 * stiffness_matrix[i].back();
        stiffness_matrix[i].back() = 0.;
    }

    stiffness_matrix.back().back() = 4.;

    // Set border condition on the left end: u(1) = -5
    for (std::size_t i = 0; i < load_vector.size(); i++) {
        load_vector[i] -= -5 * stiffness_matrix[i][0];
        stiffness_matrix[i][0] = 0.;
    }

    stiffness_matrix[0][0] = -4.;
}

void Solution::solve()
{
    Vector system = gauss(stiffness_matrix, load_vector);

    for (std::size_t i = 0, j = 0; i < system.size(); i += element->getDimension() - 1, j++) {
        solution[j] = system[i];
    }
}
