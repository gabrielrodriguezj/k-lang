#ifndef K_LANG_SCANNER_H
#define K_LANG_SCANNER_H


#include <string>
#include <cctype>
#include "Token/Token.h"

class Scanner {
private:
    std::string source;
    int linea;
    int current;

    bool match(char);
    bool isAtEnd();
    void skipWhitespace();
    char peek();
    char advance();
    char peekNext();

    Token identifier();
    TokenName identifierType(const std::string);
    Token number();
    Token string();

public:
    explicit Scanner(const std::string &source);
    Token next();
};


#endif //K_LANG_SCANNER_H
