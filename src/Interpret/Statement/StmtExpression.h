#ifndef K_LANG_STMTEXPRESSION_H
#define K_LANG_STMTEXPRESSION_H


#include "Statement.h"

class StmtExpression: public Statement{
private:
    Expression* expression;
public:
    explicit StmtExpression(Expression *expression);

    void execute(Environment*) override;

    void accept(Visitor *visitor) const override;
};


#endif //K_LANG_STMTEXPRESSION_H
