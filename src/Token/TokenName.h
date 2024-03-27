#ifndef K_LANG_TOKENNAME_H
#define K_LANG_TOKENNAME_H


#include <iostream>

enum class TokenName {
    // Tokens de un solo caracter
    LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
    COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,

    // Tokens de uno o dos caracteres
    BANG, BANG_EQUAL,
    EQUAL, EQUAL_EQUAL,
    GREATER, GREATER_EQUAL,
    LESS, LESS_EQUAL,

    // Literales
    IDENTIFIER, STRING, NUMBER,

    // Palabras clave
    AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NULL_VALUE, OR,
    PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE, EXTENDS,

    END, ERROR
};


#endif //K_LANG_TOKENNAME_H