#ifndef ERROR_HPP
#define ERROR_HPP
#include <iostream>
namespace Error
{
    class ErrorHandler
    {
    public:
        void Error(int code, std::string parameter) {}
    };
}
#endif