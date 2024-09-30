#include <map>
#include <vector>
using namespace std;
namespace Variables {
    class VariableHandler {
        map<string, int> intVars;
        map<string, string> stringVars;
        map<string, bool> boolVars;
        int GetInt(vector<string> token) {
            string name = token.at(1);
            if(token.at(0) == "symbol") {
                if(intVars.count(name) > 0) {
                    return intVars[name];
                } else {
                    
                }
            }
        }
    };
}