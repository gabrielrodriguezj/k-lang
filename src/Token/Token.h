//
// Created by gabri on 17/03/2024.
//

#ifndef K_LANG_TOKEN_H
#define K_LANG_TOKEN_H

#include "TokenName.h"

class Token {
private:
    TokenName nombre;

public:
    Token(TokenName nombre);
    TokenName getNombre();

    std::string to_string();
};


#endif //K_LANG_TOKEN_H
