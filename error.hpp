#include <iostream>
using namespace std;
namespace Error {
    class ErrorHandler {
        public:
            void Error(int code, string parameter) {
                switch(code) {
                    case 1:
                        cout << "Error: Variable" << parameter << "not found" << endl;
                        break;
                    case 2:
                        cout << "Error: Missing quotes"<< endl;
                        break;
                    case 3:
                        cout << "Error: Unexpected token" << parameter << endl;
                }
            }
    };
}