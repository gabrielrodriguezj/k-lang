#include "ScannerException.h"

ScannerException::ScannerException( const std::string &message) : message(message){}

const char* ScannerException::what() const throw()
{
    return message.c_str();
}