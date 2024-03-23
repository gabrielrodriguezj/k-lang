//
// Created by gabri on 22/03/2024.
//
#include <sstream>
#include "IdToken.h"

IdToken::IdToken(TokenName nombre, const std::string &identifier) : TToken(nombre), identifier(identifier) {}

std::string IdToken::getIdentifier(){
    return identifier;
}

std::string IdToken::toString() {
    std::stringstream ss;
    ss << "<ID , " << this->identifier << ">";
    return ss.str();;
}
