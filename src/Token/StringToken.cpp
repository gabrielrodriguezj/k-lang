//
// Created by gabri on 22/03/2024.
//
#include <sstream>
#include "StringToken.h"

StringToken::StringToken(TokenName nombre, const std::string &value, int line) : TToken(nombre, line), value(value) {}
std::string StringToken::getValue(){
    return value;
}
std::string StringToken::toString(){
    std::stringstream ss;
    ss << "< STRING , " << this->getValue() << " , line:" << TToken::getLine() << " >";
    return ss.str();;
}
