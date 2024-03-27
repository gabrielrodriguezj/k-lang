//
// Created by gabri on 17/03/2024.
//

#ifndef K_LANG_TOKEN_H
#define K_LANG_TOKEN_H

#include "TToken.h"

class Token : virtual public TToken {
private:

public:
    Token(TokenName, int);

    std::string toString();
};


#endif //K_LANG_TOKEN_H
