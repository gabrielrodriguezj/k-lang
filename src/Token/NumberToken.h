//
// Created by gabri on 22/03/2024.
//

#ifndef K_LANG_NUMBERTOKEN_H
#define K_LANG_NUMBERTOKEN_H


#include "Token.h"

class NumberToken: virtual public TToken{
private:
    double value;
public:
    NumberToken(TokenName nombre, double value);

    double getValue();
    std::string toString();
};


#endif //K_LANG_NUMBERTOKEN_H
