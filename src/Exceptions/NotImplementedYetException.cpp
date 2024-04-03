#include "NotImplementedYetException.h"

NotImplementedYetException::NotImplementedYetException( const std::string &message) : message(message){}

const char* NotImplementedYetException::what() const throw()
{
    return message.c_str();
}