#include "matrix.h"


void print(const Vector& v)
{
    for (auto &i : v) {
        std::cout << i << " ";
    }

    std::cout << std::endl;
}

void print(const Matrix& m)
{
    for (auto &v: m) {
        print(v);
    }
}

Vector gauss(const Matrix &m, const Vector &v)
{
    Vector x(m.size(), 0.);
    Matrix expanded = m;

    for (auto i = 0; i < m.size(); i++) {
        expanded[i].push_back(v[i]);
    }

    // forward phase
    for (auto k = 1; k < m.size(); k++) {
        for (auto j = k; j < m.size(); j++) {

            const double tmp = expanded[j][k - 1] / expanded[k - 1][k - 1];

            for (auto i = 0; i < m.size() + 1; i++) {
                expanded[j][i] -= tmp * expanded[k - 1][i];
            }
        }
    }

    // backward phase
    for (auto i = m.size() - 1; i >= 0; i--) {
        x[i] = expanded[i][m.size()];

        for (auto j = i + 1; j < m.size(); j++) {
            x[i] -= expanded[i][j] * x[j];
        }

        x[i] /= expanded[i][i];
    }

    return x;
}
