#include "print.hpp"
#include <iostream>
void Print::Execute(Line ln) {
    std::cout << ln.parameters.at(0).value;
};