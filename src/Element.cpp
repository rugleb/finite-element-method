#include "Element.h"

Element::Element(double l)
{
    length = l;
}

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
