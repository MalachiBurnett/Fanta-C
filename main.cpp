#include "parser.hpp"
#include "lexer.hpp"
#include <fstream>
#include <iostream>
using namespace std;
ParseHandler PH;
Lexer::LexerHandler LH;
int main(int argc, char *argv[])
{
    bool found = false;
    for (int i = 0; i < argc; i++)
    {
        string arg = argv[i];

        if (arg.length() >= 3 && arg.substr(arg.length() - 3) == ".fc")
        {
            ifstream inputCode(arg);
            string code;
            getline(inputCode, code, '\0');
            PH.Parse(LH.Lexer(code));
            inputCode.close();
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Error: no .fc file found" << endl;
    }
    return 0;
}