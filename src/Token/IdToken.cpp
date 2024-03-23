//
// Created by gabri on 22/03/2024.
//
#include <sstream>
#include "IdToken.h"

IdToken::IdToken(TokenName nombre, const std::string &identifier) : Token(nombre), identifier(identifier) {}

std::string IdToken::getIdentifier(){
    return identifier;
}

std::string IdToken::to_string() {
    std::stringstream ss;
    ss << "<ID , " << this->identifier << " >";
    return ss.str();;
}
