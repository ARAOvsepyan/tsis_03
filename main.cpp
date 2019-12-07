#include "lab_03.h"

int main() {
    std::cout << "function: cos(x)th(x)" << "\tinterval: [ 7; 11 ]\n\n";
    secondFunction sFun;
    function Fun;
    double a3 = 7.0, b3 = 11.0;
    otzhig(sFun, a3, b3);
    std::cout << std::endl;
    otzhig(Fun, a3, b3);
    return 0;
}