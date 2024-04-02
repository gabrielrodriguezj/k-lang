#include "RuntimeException.h"

RuntimeException::RuntimeException( const std::string &message) : message(message){}

const char* RuntimeException::what() const throw()
{
    return message.c_str();
}