#include <map>
#include <vector>
#include "error.hpp"
using namespace std;
namespace Variables {
    class VariableHandler {
        Error::ErrorHandler EH;
        map<string, int> intVars;
        map<string, string> strVars;
        map<string, bool> boolVars;
        public:
            int GetInt(vector<string> token) {
                string type = token.at(0);
                string name = token.at(1);
                if(type == "symbol") {
                    if(intVars.count(name) > 0) {
                        return intVars[name];
                    } else {
                        EH.Error(1, name);
                    }
                } else if (type == "number") {
                    return(stoi(name));
                } else {
                    EH.Error(1, name);
                }
            }
            string GetStr(vector<string> token) {
                string type = token.at(0);
                string name = token.at(1);
                if(type == "symbol") {
                    if(strVars.count(name) > 0) {
                        return strVars[name];
                    } else {
                        EH.Error(1, name);
                    }
                } else if (type == "string") {
                    return(name);
                } else if (type == "number") {
                    return(name);
                } else {
                    EH.Error(1, name);
                }
            }
    };
}