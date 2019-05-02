#ifndef ELEMENT_H
#define ELEMENT_H


#include <vector>

typedef std::vector<double> Vector;
typedef std::vector<Vector> Matrix;


class Element {
protected:
    double length;
    Vector load_vector;

public:
    double getLength() const;
    Vector getLoadVector() const;
};


#endif
