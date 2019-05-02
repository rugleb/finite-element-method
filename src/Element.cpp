#include "Element.h"

Element::Element(double l)
{
    length = l;
}

Element::~Element()
{
    load_vector.clear();

    for (auto &row : stiffness_matrix) {
        row.clear();
    }

    stiffness_matrix.clear();
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
