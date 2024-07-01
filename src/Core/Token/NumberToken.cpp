#include <sstream>
#include "NumberToken.h"

NumberToken::NumberToken(TokenName name, double value, int line) : TToken(name, line), value(value) {}
NumberToken::NumberToken(TokenName name, int value, int line) : TToken(name, line), value(value) {}

std::variant<int, double> NumberToken::getValue(){
    return value;
}
std::string NumberToken::toString(){
    std::stringstream ss;
    ss << "< NUMBER , " ;
    if (std::holds_alternative<int>(value)) {
        ss<<std::get<int>(value);
    }
    else{
        ss<<std::get<double>(value);
    }
    ss << " , line:" << TToken::getLine() << " >";
    return ss.str();
}