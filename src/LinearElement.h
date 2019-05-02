#ifndef LINEAR_ELEMENT_H
#define LINEAR_ELEMENT_H


#include "Element.h"


class LinearElement : public Element {
public:
    explicit LinearElement(double l) : Element(l)
    {
        load_vector = {
            -5. * l / 2.,
            -5. * l / 2.,
        };

        stiffness_matrix = {
            {
                5. / 2. - 4. / l,
                4. / l - 5. / 2,
            },
            {
                4. / l + 5. / 2.,
                -4. / l - 5. / 2.,
            }
        };
    }
};


#endif
