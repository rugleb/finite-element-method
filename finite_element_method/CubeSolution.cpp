#include "CubeSolution.h"

std::vector<std::vector<double>> CubeSolution::localMatrix(double l)
{
    // original matrix
    std::vector<std::vector<double>> matrix = {
        {
            5. / 2. - 74. / 5. / l,
            189. / 10. / l - 57. / 16.,
            3. / 2. - 27. / 5. / l,
            13. / 10. / l - 7. / 16.
        },
        {
            189. / 10. / l + 57. / 16.,
            -216. / 5. / l,
            297. / 10. / l - 81. / 16.,
            3. / 2. - 27. / 5. / l
        },
        {
            -27. / 5. / l - 3. / 2.,
            297. / 10. / l + 81. / 16.,
            -216. / 5. / l,
            189. / 10. / l - 57. / 16.
        },
        {
            13. / 10. / l + 7. / 16.,
            -27. / 5. / l - 3. / 2.,
            189. / 10. / l + 57. / 16.,
            -74. / 5. / l - 5. / 2.
        }

    };

    return matrix;
}

std::vector<double> CubeSolution::localVector(double l)
{
    // original vector
    std::vector<double> vector = {
        -5.  * l / 8.,
        -15. * l / 8.,
        -15. * l / 8.,
        -5.  * l / 8.
    };

    return vector;
}
