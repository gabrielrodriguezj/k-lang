//
// Created by gabri on 22/03/2024.
//

#ifndef K_LANG_NUMBERTOKEN_H
#define K_LANG_NUMBERTOKEN_H


#include "Token.h"

class NumberToken: public Token{
private:
    double value;
public:
    NumberToken(TokenName nombre, double value);

    double getValue();
    std::string to_string();
};


#endif //K_LANG_NUMBERTOKEN_H
