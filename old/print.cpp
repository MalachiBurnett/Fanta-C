#include <iostream>
#include <vector>
#include "variables.hpp"
#include "print.hpp"
using namespace std;
using namespace Print;

void PrintHandler::Print(vector<string> token)
{
    cout << VH.GetStr(token);
}
