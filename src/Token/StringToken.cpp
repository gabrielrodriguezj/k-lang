//
// Created by gabri on 22/03/2024.
//
#include <sstream>
#include "StringToken.h"

StringToken::StringToken(TokenName nombre, const std::string &value) : Token(nombre), value(value) {}
std::string StringToken::getValue(){
    return value;
}
std::string StringToken::to_string(){
    std::stringstream ss;
    ss << "<STRING , " << this->getValue() << " >";
    return ss.str();;
}
