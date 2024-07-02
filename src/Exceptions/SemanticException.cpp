#include "SemanticException.h"

SemanticException::SemanticException( const std::string &message) : message(message){}

const char* SemanticException::what() const throw()
{
    return message.c_str();
}