#ifndef K_LANG_STMTEXPRESSION_H
#define K_LANG_STMTEXPRESSION_H


#include "Statement.h"
#include "../Expression/Expression.h"

class StmtExpression: public Statement{
private:
    Expression* expression;
public:
    explicit StmtExpression(Expression *expression);

    void accept(Visitor *visitor) override;
};


#endif //K_LANG_STMTEXPRESSION_H
