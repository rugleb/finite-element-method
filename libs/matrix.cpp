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

    for (int i = 0; i < m.size(); i++) {
        expanded[i].push_back(v[i]);
    }

    // forward phase
    for (int k = 1; k < m.size(); k++) {
        for (int j = k; j < m.size(); j++) {

            const double tmp = expanded[j][k - 1] / expanded[k - 1][k - 1];

            for (int i = 0; i < m.size() + 1; i++) {
                expanded[j][i] -= tmp * expanded[k - 1][i];
            }
        }
    }

    // backward phase
    for (int i = m.size() - 1; i >= 0; i--) {
        x[i] = expanded[i][m.size()];

        for (int j = i + 1; j < m.size(); j++) {
            x[i] -= expanded[i][j] * x[j];
        }

        x[i] /= expanded[i][i];
    }

    return x;
}
