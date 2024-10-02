






































#include <map>
#include <vector>
#include "error.hpp"
#include "variables.hpp"
using namespace std;
namespace Variables
{
    void VariableHandler::assignvalue(vector<string> token, vector<string> value)
    {
        if (token.at(0) == "symbol")
        {
        }
    }
    int VariableHandler::GetInt(vector<string> token)
    {
        string type = token.at(0);
        string name = token.at(1);
        if (type == "symbol")
        {
            if (intVars.count(name) > 0)
            {
                return intVars[name];
            }
            else
            {
                EH.Error(1, name);
                return 0;
            }
        }
        else if (type == "number")
        {
            return (stoi(name));
        }
        else
        {
            EH.Error(1, name);
            return 0;
        }
    }
    string VariableHandler::GetStr(vector<string> token)
    {
        string type = token.at(0);
        string name = token.at(1);
        if (type == "symbol")
        {
            if (strVars.count(name) > 0)
            {
                return strVars[name];
            }
            else
            {
                EH.Error(1, name);
                return " ";
            }
        }
        else if (type == "string")
        {
            return (name);
        }
        else if (type == "number")
        {
            return (name);
        }
        else
        {
            EH.Error(1, name);
            return " ";
        }
    }
};