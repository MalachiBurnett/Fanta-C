#include <iostream>
using namespace std;
namespace error {
    class ErrorHandler {
        void Error(int code, string parameter) {
            switch(code) {
                case 1:
                    cout << "Error: Variable" << parameter << "not found" << endl;
            }
        }
    };
}