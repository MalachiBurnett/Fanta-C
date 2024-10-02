#include <iostream>
#include <vector>
#include "variables.hpp"
using namespace std;
namespace print
{
    class PrintHandler
    {
        Variables::VariableHandler VH;
        public:
        void Print(vector<string> token) {
            cout << VH.GetStr(token);
        }
    };
}