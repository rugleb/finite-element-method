#ifndef CUBE_ELEMENT_H
#define CUBE_ELEMENT_H


#include "Element.h"


class CubeElement : public Element {
public:
    explicit CubeElement(double l) : Element(l)
    {
        load_vector = {
            -5. * l / 8.,
            -15. * l / 8.,
            -15. * l / 8.,
            -5. * l / 8.,
        };

        stiffness_matrix = {
            {
                5. / 2. - 74. / 5. / l,
                189. / 10. / l - 57. / 16.,
                3. / 2. - 27. / 5. / l,
                13. / 10. / l - 7. / 16.,
            },
            {
                189. / 10. / l + 57. / 16.,
                -216. / 5. / l,
                297. / 10. / l - 81. / 16.,
                3. / 2. - 27. / 5. / l,
            },
            {
                -27. / 5. / l - 3. / 2.,
                297. / 10. / l + 81. / 16.,
                -216. / 5. / l,
                189. / 10. / l - 57. / 16.,
            },
            {
                13. / 10. / l + 7. / 16.,
                -27. / 5. / l - 3. / 2.,
                189. / 10. / l + 57. / 16.,
                -74. / 5. / l - 5. / 2.,
            }
        };
    }
};


#endif
