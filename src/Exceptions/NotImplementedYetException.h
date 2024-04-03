#ifndef K_LANG_NOTIMPLEMENTEDYETEXCEPTION_H
#define K_LANG_NOTIMPLEMENTEDYETEXCEPTION_H


#include <exception>
#include <string>

class NotImplementedYetException : public std::exception{

private:
    std::string message;

public:
    NotImplementedYetException(const std::string &);
    const char* what() const throw();
};


#endif //K_LANG_NOTIMPLEMENTEDYETEXCEPTION_H
