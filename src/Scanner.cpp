#include <sstream>
#include "Scanner.h"
#include "Token/Token.h"
#include "Token/IdToken.h"
#include "Token/StringToken.h"
#include "Token/NumberToken.h"
#include "Exceptions/ScannerException.h"

Scanner::Scanner(const std::string &source) : source(source) {
    this->source.append(" ");
    line = 1;
    current = 0;
}

bool Scanner::match(char expected) {
    if (isAtEnd()) return false;
    if (source.at(current) != expected) return false;
    current++;
    return true;
}

bool Scanner::isAtEnd(){
    return current >= source.length();
}

void Scanner::skipWhitespace() {
    for (;;) {
        char c = peek();
        switch (c) {
            case ' ':
            case '\r':
            case '\t':
                advance();
                break;
            case '\n':
                line++;
                advance();
                break;
            case '/':
                if (peekNext() == '/') {
                    // Un comentario de una linea termina con el salto de línea
                    while (peek() != '\n' && !isAtEnd()) advance();
                }
                else if (peekNext() == '*') {
                    // Consumir el "/*"
                    advance();
                    advance();
                    // Un comentario multilinea termina con "*/"
                    bool openComment = true;
                    do {
                        if (peek() == '*' && !isAtEnd()) advance();
                        if (peek() == '/') {
                            openComment = false;
                        }
                        advance();
                    }while (openComment);

                }
                else {
                    return;
                }
                break;
            default:
                return;
        }
    }
}

char Scanner::peek() {
    if (isAtEnd()) return '\0';
    char c = source.at(current);
    return c;
}

char Scanner::advance() {
    current++;
    return source.at(current-1);
}

char  Scanner::peekNext() {
    if (isAtEnd()) return '\0';
    char c = source.at(current + 1);
    return c;
}

TToken* Scanner::identifier() {
    int begin = this->current - 1;
    while (isalpha(peek()) || isdigit(peek())) advance();
    int end = this->current - 1;
    std::string lexem = source.substr(begin, end - begin + 1);
    TokenName nt = identifierType(lexem);

    if(nt == TokenName::IDENTIFIER){
        return new IdToken(nt, lexem, line);
    }
    return new Token(nt, line);
}

TokenName Scanner::identifierType(const std::string lexem){
    if(lexem == "and") return TokenName::AND;
    if(lexem == "class") return TokenName::CLASS;
    if(lexem == "else") return TokenName::ELSE;
    if(lexem == "false") return TokenName::FALSE;
    if(lexem == "fun") return TokenName::FUN;
    if(lexem == "for") return TokenName::FOR;
    if(lexem == "if") return TokenName::IF;
    if(lexem == "null") return TokenName::NULL_VALUE;
    if(lexem == "or") return TokenName::OR;
    if(lexem == "print") return TokenName::PRINT;
    if(lexem == "return") return TokenName::RETURN;
    if(lexem == "super") return TokenName::SUPER;
    if(lexem == "this") return TokenName::THIS;
    if(lexem == "true") return TokenName::TRUE;
    if(lexem == "var") return TokenName::VAR;
    if(lexem == "while") return TokenName::WHILE;
    if(lexem == "extends") return TokenName::EXTENDS;
    return TokenName::IDENTIFIER;
}

TToken* Scanner::number() {
    int begin = current-1;
    while (isdigit(peek())) advance();

    // Checar si existe parte decimal
    if (peek() == '.' && isdigit(peekNext())) {
        // Consumir el "."
        advance();

        while (isdigit(peek())) advance();
    }
    if(peek() == 'E' && (peekNext() == '+' || peekNext() == '-'  || isdigit(peekNext()))){
        // consumir el "E"
        advance();

        if((peek() == '+' || peek() == '-'  )){
            advance();
        }
        while (isdigit(peek())) advance();
    }

    int end = current - 1;

    //std::cout<<this->source.substr(begin, end-begin + 1);
    double value = std::stod(source.substr(begin, end-begin + 1));
    return new NumberToken(TokenName::NUMBER, value, line);
}

TToken* Scanner::string() {
    int begin = current-1;

    while (peek() != '"' && !isAtEnd()) {
        if (peek() == '\n') line++;
        advance();
    }
    if (isAtEnd()) {
        //return new Token(TokenName::ERROR, line);
        std::stringstream ss;
        ss << "Error: La cadena no se cerró apropiadamente. Linea: " << line;
        throw new ScannerException(ss.str());
    }

    // La comilla que cierra.
    advance();

    int end = current - 1;

    //std::cout<<this->source.substr(begin, end-begin + 1);
    return  new StringToken(TokenName::STRING, source.substr(begin + 1, end - begin - 1), line);
}

TToken* Scanner::next() {
    skipWhitespace();

    if (isAtEnd()) return new Token(TokenName::END, line);

    char c = advance();

    if (isalpha(c)) return identifier();
    else if(isdigit(c)) return number();

    switch (c) {
        case '(': return new Token(TokenName::LEFT_PAREN, line);
        case ')': return new Token(TokenName::RIGHT_PAREN, line);
        case '{': return new Token(TokenName::LEFT_BRACE, line);
        case '}': return new Token(TokenName::RIGHT_BRACE, line);
        case ';': return new Token(TokenName::SEMICOLON, line);
        case ',': return new Token(TokenName::COMMA, line);
        case '.': return new Token(TokenName::DOT, line);
        case '-': return new Token(TokenName::MINUS, line);
        case '+': return new Token(TokenName::PLUS, line);
        case '/': return new Token(TokenName::SLASH, line);
        case '*': return new Token(TokenName::STAR, line);
        case '!':
            return new Token(
                    match('=') ? TokenName::BANG_EQUAL : TokenName::BANG, line);
        case '=':
            return new Token(
                    match('=') ? TokenName::EQUAL_EQUAL : TokenName::EQUAL, line);
        case '<':
            return new Token(
                    match('=') ? TokenName::LESS_EQUAL : TokenName::LESS, line);
        case '>':
            return new Token(
                    match('=') ? TokenName::GREATER_EQUAL : TokenName::GREATER, line);
        case '"': return string();
    }

    //return new Token(TokenName::ERROR, line);
    std::stringstream ss;
    ss<<"Error: caracter '" << peek() << "' no válido. Linea: " << line;
    throw new ScannerException(ss.str());

}
