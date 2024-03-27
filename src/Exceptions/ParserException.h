#ifndef K_LANG_PARSEREXCEPTION_H
#define K_LANG_PARSEREXCEPTION_H

#include <exception>
#include <string>

class ParserException : public std::exception{

private:
    std::string message;

public:
    ParserException(const std::string &);
    const char* what() const throw();
};



#endif //K_LANG_PARSEREXCEPTION_H
