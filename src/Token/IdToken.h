#ifndef K_LANG_IDTOKEN_H
#define K_LANG_IDTOKEN_H


#include "Token.h"
#include "TToken.h"

class IdToken : virtual public TToken{
private:
    const std::string identifier;

public:
    IdToken(TokenName nombre, const std::string &lexem);

    std::string getIdentifier();
    std::string toString();
};


#endif //K_LANG_IDTOKEN_H
