#ifndef K_LANG_STMTEXPRESSION_H
#define K_LANG_STMTEXPRESSION_H


#include "Inter/Statement.h"
#include "Inter/Expression.h"

class StmtExpression: public Statement{
private:
    Expression* expression;
public:
    explicit StmtExpression(Expression *expression);

    void execute() override;
};


#endif //K_LANG_STMTEXPRESSION_H