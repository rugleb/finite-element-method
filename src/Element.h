#ifndef ELEMENT_H
#define ELEMENT_H


#include "../libs/matrix.h"


class Element {
protected:
    double length;
    Vector load_vector;
    Matrix stiffness_matrix;

public:
    explicit Element(double l);
    ~Element();

    double getLength() const;
    Vector getLoadVector() const;
    Matrix getStiffnessMatrix() const;
};


#endif
