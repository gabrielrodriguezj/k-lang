#include <sstream>
#include "IdToken.h"

IdToken::IdToken(TokenName name, const std::string &identifier, int line) : TToken(name, line), identifier(identifier) {}

std::string IdToken::getIdentifier(){
    return identifier;
}

std::string IdToken::toString() {
    std::stringstream ss;
    ss << "< ID , " << this->identifier << " , line:" << TToken::getLine() << " >";
    return ss.str();;
}
