#include <vector>
#include "error.hpp"
using namespace std;

namespace Lexer
{
    class LexerHandler
    {
        Error::ErrorHandler EH;
        bool Contains(const vector<string> vec, const string value) {}
        bool CheckContents(string strToCheck, string characters) {}
        vector<string> Split(string str, char delimiter) {}
    public:
        vector<vector<vector<string>>> Lexer(string code) {}
    };
}