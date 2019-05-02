#include <string>

#include "src/Solution.h"
#include "src/CubeElement.h"
#include "src/LinearElement.h"


#define LEFT_BORDER     1.
#define RIGHT_BORDER    19.


int main(int argc, char* argv[])
{
    // number of finite elements
    int elements = argc > 1 ? std::stoi(argv[1]) : 10;

    // length of finite element
    double length = (RIGHT_BORDER - LEFT_BORDER) / elements;

    auto cube = new CubeElement(length);
    auto linear = new LinearElement(length);

    return 0;
}
