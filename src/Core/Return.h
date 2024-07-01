#ifndef K_LANG_RETURN_H
#define K_LANG_RETURN_H


#include <exception>
#include <string>
#include "TData.h"

class Return : public std::exception{

private:
    std::string message;
    TData value;
public:
    Return (const std::string &, TData);
    const char* what() const throw();
    TData getValue();
};


#endif //K_LANG_RETURN_H
