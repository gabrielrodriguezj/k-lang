#ifndef K_LANG_PARSER_H
#define K_LANG_PARSER_H


#include <string>
#include <list>
#include "Token/TToken.h"
#include "Scanner.h"
#include "Inter/Expression.h"

class Parser {
private:
    Scanner* scanner;
    TToken* preanalysis{};
    TToken* previous{};

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
    Expression* expression();
    Expression* assignament();
    Expression* assignamentOptional(Expression*);
    Expression*  logicOr();
    Expression*  logicOr2(Expression*);
    Expression* logicAnd();
    Expression* logicAnd2(Expression*);
    Expression* equality();
    Expression* equality2(Expression*);
    Expression* comparison();
    Expression* comparison2(Expression*);
    Expression* term();
    Expression* term2( Expression*);
    Expression* factor();
    Expression* factor2(Expression*);
    Expression* unary();
    Expression* call();
    Expression* call2(Expression*);
    Expression* primary();

    //Auxiliary
    void parametersOptional();
    void parameters();
    void parameters2();
    std::list<Expression*> argumentsOptional();
    void arguments();
public:
    explicit Parser(const std::string&);
    bool parse();
};

#endif //K_LANG_PARSER_H
