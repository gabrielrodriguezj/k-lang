#ifndef K_LANG_PARSER_H
#define K_LANG_PARSER_H


#include <string>
#include "Token/TToken.h"
#include "Scanner.h"
#include "Inter/Expression.h"

class Parser {
private:
    Scanner* scanner;
    TToken* preanalysis{};

    void match(TokenName);

    //Declarations:
    void program();
    void declaration();
    void classDeclaration();
    void classInheritance();
    void classElement();
    void functionDeclaration();
    void variableDeclaration();
    void variableInitialization();

    //Statements
    void statement();
    void expressionStatement();
    void forStatement();
    void forStatement1();
    void forStatement2();
    void forStatement3();
    void ifStatement();
    void elseStatement();
    void printStatement();
    void returnStatement();
    void returnExpressionOptional();
    void whileStatement();
    void block();

    //Expressions
    void expression();
    void assignament();
    void assignamentOptional();
    void logicOr();
    void logicOr2();
    void logicAnd();
    void logicAnd2();
    void equality();
    void equality2();
    void comparison();
    void comparison2();
    void term();
    void term2();
    void factor();
    void factor2();
    void unary();
    void call();
    void call2();
    Expression* primary();

    //Auxiliary
    void parametersOptional();
    void parameters();
    void parameters2();
    void argumentsOptional();
    void arguments();
public:
    explicit Parser(const std::string&);
    bool parse();
};

#endif //K_LANG_PARSER_H
