#include "error.hpp"
#include <iostream>
using namespace std;
using namespace Error;
void ErrorHandler::Error(int code, string parameter)
{
    switch (code)
    {
    case 1:
        cout << "Error: Variable" << parameter << "not found" << endl;
        break;
    case 2:
        cout << "Error: Missing quotes" << endl;
        break;
    case 3:
        cout << "Error: Unexpected token" << parameter << endl;
        break;
    case 4:
        cout << "Error: Missing cloing brackets" << endl;
        break;
    }
}