#ifndef PARSER_HPP
#define PARSER_HPP
#include "print.hpp"
#include "variables.hpp"
#include <vector>
#include <map>
class ParseHandler {
    Print::PrintHandler PH;
    Variables::VariableHandler VH;
    map<std::string, int> labels;
public:
    virtual void Parse(std::vector<std::vector<std::vector<std::string>>> tokens) {}
};
#endif