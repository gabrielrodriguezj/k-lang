#ifndef K_LANG_SCANNER_H
#define K_LANG_SCANNER_H


#include <string>
#include <cctype>
#include "Core/Token/TToken.h"

class Scanner {
private:
    std::string source;
    int line;
    int current;

    bool match(char);
    bool isAtEnd();
    void skipWhitespace();
    char peek();
    char advance();
    char peekNext();

    TToken* identifier();
    TokenName identifierType(const std::string);
    TToken* number();
    TToken* string();

public:
    explicit Scanner(const std::string &source);
    TToken* next();
};


#endif //K_LANG_SCANNER_H
