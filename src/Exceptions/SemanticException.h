#ifndef K_LANG_SEMANTICEXCEPTION_H
#define K_LANG_SEMANTICEXCEPTION_H

#include <exception>
#include <string>

class SemanticException : public std::exception{
private:
    std::string message;

public:
    SemanticException(const std::string &);
    const char* what() const throw();
};


#endif //K_LANG_SEMANTICEXCEPTION_H
