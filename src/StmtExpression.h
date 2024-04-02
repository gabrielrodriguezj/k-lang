#ifndef K_LANG_STMTEXPRESSION_H
#define K_LANG_STMTEXPRESSION_H


#include "Inter/Expression.h"

class StmtExpression: public Expression{
private:
    Expression* expression;
public:
    explicit StmtExpression(Expression *expression);
    TData solve() override;
};


#endif //K_LANG_STMTEXPRESSION_H
