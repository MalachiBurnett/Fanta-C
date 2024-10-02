#ifndef LEXER_HPP
#define LEXER_HPP
#include <vector>
#include "error.hpp"
using namespace std;

namespace Lexer
{
    class LexerHandler
    {
        Error::ErrorHandler EH;
        bool Contains(const vector<string> vec, const string value) {return false;}
        bool CheckContents(string strToCheck, string characters) {return false;}
        vector<string> Split(string str, char delimiter) {return vector<string>();}
    public:
        vector<vector<vector<string>>> Lexer(string code) {return vector<vector<vector<string>>>();}
    };
}
#endif