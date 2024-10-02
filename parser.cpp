#include "lexer.hpp"
#include "print.hpp"
#include "variables.hpp"
#include <vector>
using namespace std;
class ParseHandler {
    Lexer::LexerHandler LH;
    
    public:
    void parse(vector<vector<vector<string>>> tokens) {
        int linenum = 0;
        while (linenum < tokens.size()) {
            vector<vector<string>> line = tokens.at(linenum);
        }
    }
};