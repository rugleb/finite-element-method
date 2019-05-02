#ifndef ELEMENT_H
#define ELEMENT_H


#include <vector>

typedef std::vector<double> Vector;
typedef std::vector<Vector> Matrix;


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
