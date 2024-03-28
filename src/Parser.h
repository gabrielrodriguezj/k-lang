#ifndef K_LANG_PARSER_H
#define K_LANG_PARSER_H


#include <string>
#include "Token/TToken.h"
#include "Scanner.h"
#include "Exceptions/ParserException.h"

class Parser {
private:
    Scanner* scanner;
    TToken* preanalysis;

    void match(TokenName) noexcept(false);

    //Declarations:
    void program() noexcept(false);
    void declaration() noexcept(false);
    void classDeclaration() noexcept(false);
    void classInheritance() noexcept(false);
    void classElement() noexcept(false);
    void functionDeclaration() noexcept(false);
    void variableDeclaration() noexcept(false);
    void variableInitialization() noexcept(false);

    //Statements
    void statement() noexcept(false);
    void expressionStatement() noexcept(false);
    void forStatement() noexcept(false);
    void forStatement1() noexcept(false);
    void forStatement2() noexcept(false);
    void forStatement3() noexcept(false);
    void ifStatement() noexcept(false);
    void elseStatement() noexcept(false);
    void printStatement() noexcept(false);
    void returnStatement() noexcept(false);
    void returnExpressionOptional() noexcept(false);
    void whileStatement() noexcept(false);
    void block() noexcept(false);

    //Expressions
    void expression() noexcept(false);
    void assignament() noexcept(false);
    void assignamentOptional() noexcept(false);
    void logicOr() noexcept(false);
    void logicOr2() noexcept(false);
    void logicAnd() noexcept(false);
    void logicAnd2() noexcept(false);
    void equality() noexcept(false);
    void equality2() noexcept(false);
    void comparison() noexcept(false);
    void comparison2() noexcept(false);
    void term() noexcept(false);
    void term2() noexcept(false);
    void factor() noexcept(false);
    void factor2() noexcept(false);
    void unary() noexcept(false);
    void call() noexcept(false);
    void call2() noexcept(false);
    void primary() noexcept(false);

    //Auxiliary
    void parametersOptional() noexcept(false);
    void parameters() noexcept(false);
    void parameters2() noexcept(false);
    void argumentsOptional() noexcept(false);
    void arguments() noexcept(false);
public:
    Parser(std::string);
    bool parse();
};


#endif //K_LANG_PARSER_H
