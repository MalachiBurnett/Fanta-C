#ifndef ERROR_HPP
#define ERROR_HPP
#include <iostream>
namespace Error
{
    class ErrorHandler
    {
    public:
        virtual void Error(int code, std::string parameter) {}
    };
}
#endif