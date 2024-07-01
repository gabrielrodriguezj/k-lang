#ifndef K_LANG_RETURN_H
#define K_LANG_RETURN_H


#include <exception>
#include <string>
#include "KData.h"

class Return : public std::exception{

private:
    std::string message;
    KData value;
public:
    Return (const std::string &, KData);
    const char* what() const throw();
    KData getValue();
};


#endif //K_LANG_RETURN_H
