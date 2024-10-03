#ifndef LEXER_HPP
#define LEXER_HPP
#include <vector>
#include "error.hpp"
namespace Lexer
{
    class LexerHandler
    {
        Error::ErrorHandler EH;
        virtual bool Contains(const std::vector<std::string> vec, const std::string value) {return false;}
        virtual bool CheckContents(std::string strToCheck, std::string characters) {return false;}
        virtual std::vector<string> Split(std::string str, char delimiter) {return vector<string>();}
    public:
        virtual std::vector<std::vector<std::vector<std::string>>> Lexer(std::string code) {return std::vector<std::vector<std::vector<std::string>>>();}
    };
}
#endif