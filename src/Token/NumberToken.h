#ifndef K_LANG_NUMBERTOKEN_H
#define K_LANG_NUMBERTOKEN_H


#include "Token.h"

class NumberToken: virtual public TToken{
private:
    double value;
public:
    NumberToken(TokenName, double, int);

    double getValue();
    std::string toString();
};


#endif //K_LANG_NUMBERTOKEN_H
