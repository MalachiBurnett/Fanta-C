#include "print.hpp"
#include "variables.hpp"
#include <vector>
#include <map>
using namespace std;
class ParseHandler {
    Print::PrintHandler PH;
    Variables::VariableHandler VH;
    map<string, int> labels;
    public:
    void Parse(vector<vector<vector<string>>> tokens) {
        int lineNum = 0;
        for (vector<vector<string>> line : tokens) {
            lineNum++;
            if(line.at(0).at(1) == "label") {
                if(line.at(0).at(0) == "symbol") {
                    if(line.at(1).at(0) == "string") {
                        labels[line.at(1).at(1)] = lineNum;
                    }
                }
            }
        }
        lineNum = 0;
        int size = tokens.size();
        while(lineNum < size) {
            vector<vector<string>> line = tokens.at(lineNum);
            if(line.at(0).at(0) == "symbol") {
                if(line.at(0).at(1) == "Print") {
                    PH.Print(line.at(1));                }
            }
            lineNum++;
        }
    }
};