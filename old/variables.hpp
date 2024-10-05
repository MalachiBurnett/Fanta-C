#ifndef VARIABLES_HPP
#define VARIABLES_HPP
#include <vector>
#include <map>
#include "error.hpp"
using namespace std;
namespace Variables {
    class VariableHandler {
        Error::ErrorHandler EH;
        map<string, int> intVars;
        map<string, string> strVars;
        public:
        virtual void assignvalue(vector<string> token, vector<string> value) {}
        virtual string GetStr(vector<string> token) {return "something";}
        virtual int GetInt(vector<string> token) {return 0;}
    };
}
#endif