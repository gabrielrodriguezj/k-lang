//
// Created by gabri on 22/03/2024.
//
#include <sstream>
#include "NumberToken.h"

NumberToken::NumberToken(TokenName nombre, double value) : TToken(nombre), value(value) {}

double NumberToken::getValue(){
    return value;
}
std::string NumberToken::toString(){
    std::stringstream ss;
    ss << "<NUMBER , " << this->getValue() << ">";
    return ss.str();;
}