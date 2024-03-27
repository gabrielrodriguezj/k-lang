//
// Created by gabri on 22/03/2024.
//
#include <sstream>
#include "NumberToken.h"

NumberToken::NumberToken(TokenName name, double value, int line) : TToken(name, line), value(value) {}

double NumberToken::getValue(){
    return value;
}
std::string NumberToken::toString(){
    std::stringstream ss;
    ss << "< NUMBER , " << this->getValue() << " , line:" << TToken::getLine() << " >";
    return ss.str();;
}