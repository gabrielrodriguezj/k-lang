#ifndef K_LANG_PARSER_H
#define K_LANG_PARSER_H


#include <string>
#include <list>
#include "Token/TToken.h"
#include "Scanner.h"
#include "Inter/Expression.h"
#include "Inter/Statement.h"
#include "Inter/ExprVariable.h"
#include "Inter/StmtFunction.h"
#include "Inter/StmtVariable.h"
#include "StmtExpression.h"

class Parser {
private:
    Scanner* scanner;
    TToken* preanalysis{};
    TToken* previous{};

    void match(TokenName);

    //Declarations:
    void program();
    void declaration(std::list<Statement*>);
    Statement* classDeclaration();
    ExprVariable* classInheritance();
    void classElement(std::list<StmtFunction*>, std::list<StmtVariable*>);
    StmtFunction* functionDeclaration();
    StmtVariable* variableDeclaration();
    Expression* variableInitialization();

    //Statements
    Statement* statement();
    StmtExpression* expressionStatement();
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
    StmtBlock* block();

    //Expressions
    Expression* expression();
    Expression* assignament();
    Expression* assignamentOptional(Expression*);
    Expression* logicOr();
    Expression* logicOr2(Expression*);
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
    std::list<IdToken*> parametersOptional();
    void parameters(std::list<IdToken*>);
    void parameters2(std::list<IdToken*>);
    std::list<Expression*> argumentsOptional();
    void arguments();
public:
    explicit Parser(const std::string&);
    bool parse();
};

#endif //K_LANG_PARSER_H
