#include "src/CubeElement.h"
#include "src/LinearElement.h"

int main(int argc, char* argv[])
{
    double length = 1.;

    auto cube = new CubeElement(length);
    auto linear = new LinearElement(length);

    return 0;
}
