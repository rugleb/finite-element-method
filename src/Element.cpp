#include "Element.h"

double Element::getLength() const
{
    return length;
}

Vector Element::getLoadVector() const
{
    return load_vector;
}

Matrix Element::getStiffnessMatrix() const
{
    return stiffness_matrix;
}
