//
// Created by gabri on 22/03/2024.
//

#ifndef K_LANG_STRINGTOKEN_H
#define K_LANG_STRINGTOKEN_H


#include "Token.h"

class StringToken : virtual public TToken{
private:
    const std::string value;
public:
    StringToken(TokenName, const std::string &, int);
    std::string getValue();
    std::string toString();
};


#endif //K_LANG_STRINGTOKEN_H
