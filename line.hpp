#ifndef LINE_HPP
#define LINE_HPP
#include "symbol.hpp"
#include "token.hpp"
#include <vector>
class Line
{
    public:
    Symbol function;
    std::vector<Token> parameters;
};
#endif