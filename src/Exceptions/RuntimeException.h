#ifndef K_LANG_RUNTIMEEXCEPTION_H
#define K_LANG_RUNTIMEEXCEPTION_H


#include <exception>
#include <string>

class RuntimeException : public std::exception{

private:
    std::string message;

public:
    RuntimeException(const std::string &);
    const char* what() const throw();
};


#endif //K_LANG_RUNTIMEEXCEPTION_H
