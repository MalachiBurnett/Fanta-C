#ifndef PRINT_HPP
#define PRINT_HPP
#include "variables.hpp"
namespace Print {
    class PrintHandler {
        Variables::VariableHandler VH;
        public:
        virtual void Print(std::vector<std::string> token) {}
    };
}
#endif