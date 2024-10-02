#include "lexer.hpp"
#include <algorithm>
#include <string>
using namespace Lexer;
using namespace std;
bool LexerHandler::Contains(const vector<string> vec, const string value)
{
    return find(vec.begin(), vec.end(), value) != vec.end();
}

bool LexerHandler::CheckContents(string strToCheck, string characters)
{
    bool found = false;
    for (char c : strToCheck)
    {
        found = false;
        for (char d : characters)
        {
            if (c == d)
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            return false;
        }
    }
    return true;
}

vector<string> LexerHandler::Split(string str, char delimiter)
{
    vector<string> result = {};
    string tempStr = "";
    bool quotes = true;
    bool brackets = true;
    for (int i = 0; i < str.size(); i++)
    {
        if (str.at(i) == '"')
        {
            quotes = !quotes;
        }
        if (str.at(i) == ')') {
            brackets = !brackets;
        }
        if (str.at(i) == delimiter && quotes && brackets)
        {
            result.push_back(tempStr);
            tempStr = "";
        }
        else
        {
            tempStr += str.at(i);
        }
    }
    if (!tempStr.empty())
    {
        result.push_back(tempStr);
    }
    if (!brackets) {
        EH.Error(4, "");
    }
    if (!quotes)
    {
        EH.Error(2, "");
        return {};
    }
    return result;
}

vector<vector<vector<string>>> LexerHandler::Lexer(string code)
{
    vector<string> lines = Split(code, '\n');
    vector<vector<vector<string>>> result = {};
    for (string line : lines)
    {
        if (line.empty())
            continue;
        vector<string> tokens = Split(line, ' ');
        vector<vector<string>> items = {};
        for (string token : tokens)
        {
            vector<string> item = {};
            if (token[0] == '"' && token[token.size() - 1] == '"')
            {
                item.push_back("string");
                token = token.substr(1, token.size() - 2);
            }
            else if (CheckContents(token, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"))
            {
                item.push_back("symbol");
            }
            else if (CheckContents(token, "+-*/%=><!=<>="))
            {
                item.push_back("expression");
            }
            else if (CheckContents(token, "0123456789"))
            {
                item.push_back("number");
            }
            else
            {
                EH.Error(3, token);
                continue;
            }
            item.push_back(token);
            items.push_back(item);
        }
        result.push_back(items);
    }
    return result;
}