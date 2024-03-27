#include "ParserException.h"

ParserException::ParserException( const std::string &message) : message(message){}

const char* ParserException::what() const throw()
{
    return message.c_str();
}