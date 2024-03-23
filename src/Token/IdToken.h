#ifndef K_LANG_IDTOKEN_H
#define K_LANG_IDTOKEN_H


#include "Token.h"

class IdToken : public Token{
private:
    const std::string identifier;

public:
    IdToken(TokenName nombre, const std::string &lexem);

    std::string getIdentifier();
    std::string to_string();
};


#endif //K_LANG_IDTOKEN_H
