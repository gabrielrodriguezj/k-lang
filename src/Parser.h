#ifndef K_LANG_PARSER_H
#define K_LANG_PARSER_H


#include <string>
#include <list>
#include "Token/TToken.h"
#include "Scanner.h"
#include "Inter/Expression/Expression.h"
#include "Inter/Statement/Statement.h"
#include "Inter/Expression/ExprVariable.h"
#include "Inter/Statement/StmtFunction.h"
#include "Inter/Statement/StmtVariable.h"
#include "StmtExpression.h"

class Parser {
private:
    Scanner* scanner;
    TToken* preanalysis{};
    TToken* previous{};
    std::list<Statement*> stmts{};

    void match(TokenName);

    //Declarations:
    std::list<Statement*> program();
    void declaration(std::list<Statement*>&);
    Statement* classDeclaration();
    ExprVariable* classInheritance();
    void classElement(std::list<StmtFunction*>&, std::list<StmtVariable*>&);
    StmtFunction* functionDeclaration();
    StmtVariable* variableDeclaration();
    Expression* variableInitialization();

    //Statements
    Statement* statement();
    StmtExpression* expressionStatement();
    Statement* forStatement();
    Statement* forStatementInit();
    Expression* forStatementCondition();
    Expression* forStatementIncrease();
    Statement* ifStatement();
    Statement* elseStatement();
    Statement* printStatement();
    Statement* returnStatement();
    Expression* returnExpressionOptional();
    Statement* whileStatement();
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
    void parameters(std::list<IdToken*>&);
    void parameters2(std::list<IdToken*>&);
    void argumentsOptional(std::list<Expression*>&);
    void arguments(std::list<Expression*>&);
public:
    explicit Parser(const std::string&);
    bool parse();
    std::list<Statement*> getStatements();
};

#endif //K_LANG_PARSER_H
