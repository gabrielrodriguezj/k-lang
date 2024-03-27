#include <sstream>
#include "Token.h"
#include "TokenUtil.h"

Token::Token(TokenName name, int line) : TToken(name, line) {}

std::string Token::toString() {
    std::stringstream ss;
    ss << "< " << tokennameToString(TToken::getName());
    ss << " , line:" << TToken::getLine() << " >";
    return ss.str();;
}
