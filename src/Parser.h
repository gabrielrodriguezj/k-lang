#ifndef K_LANG_PARSER_H
#define K_LANG_PARSER_H


#include <string>
#include <vector>
#include "Scanner.h"
#include "Core/Expression/Expression.h"
#include "Core/Statement/Statement.h"
#include "Core/Expression/ExprVariable.h"
#include "Core/Statement/StmtFunction.h"
#include "Core/Statement/StmtVariable.h"
#include "Core/Statement/StmtExpression.h"
#include "Core/Token/IdToken.h"

class Parser {
private:
    Scanner* scanner;
    TToken* preanalysis{};
    TToken* previous{};
    std::vector<Statement*> stmts{};

    void match(TokenName);

    //Declarations:
    std::vector<Statement*> program();
    void declaration(std::vector<Statement*>&);
    Statement* classDeclaration();
    ExprVariable* classInheritance();
    void classElement(std::vector<StmtFunction*>&, std::vector<StmtVariable*>&);
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
    std::vector<IdToken*> parametersOptional();
    void parameters(std::vector<IdToken*>&);
    void parameters2(std::vector<IdToken*>&);
    void argumentsOptional(std::vector<Expression*>&);
    void arguments(std::vector<Expression*>&);
public:
    explicit Parser(const std::string&);
    bool parse();
    std::vector<Statement*> getStatements();
};

#endif //K_LANG_PARSER_H
