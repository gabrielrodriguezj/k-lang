#ifndef K_LANG_NUMBERTOKEN_H
#define K_LANG_NUMBERTOKEN_H


#include <variant>
#include "Token.h"

class NumberToken: virtual public TToken{
private:
    std::variant<int, double> value;
public:
    NumberToken(TokenName, double, int);
    NumberToken(TokenName, int, int);

    std::variant<int, double> getValue();
    std::string toString();
};


#endif //K_LANG_NUMBERTOKEN_H
