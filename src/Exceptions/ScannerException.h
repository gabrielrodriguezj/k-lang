#ifndef K_LANG_SCANNEREXCEPTION_H
#define K_LANG_SCANNEREXCEPTION_H

#include <exception>
#include <string>

class ScannerException: public std::exception{

private:
    std::string message;

public:
    ScannerException(const std::string &);
    const char* what() const throw();
};


#endif //K_LANG_SCANNEREXCEPTION_H
