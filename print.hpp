#ifndef PRINT_HPP
#define PRINT_HPP
#include "symbol.hpp"
class Print : public Symbol {
    public:
    void Execute(Line Ln);
};
#endif