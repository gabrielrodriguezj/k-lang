//
// Created by gabri on 22/03/2024.
//

#ifndef K_LANG_STRINGTOKEN_H
#define K_LANG_STRINGTOKEN_H


#include "Token.h"

class StringToken : public Token{
private:
    const std::string value;
public:
    StringToken(TokenName nombre, const std::string &value);
    std::string getValue();
    std::string to_string();
};


#endif //K_LANG_STRINGTOKEN_H
