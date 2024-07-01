#ifndef K_LANG_STMTLOOP_H
#define K_LANG_STMTLOOP_H


#include "Statement.h"
#include "../Expression/Expression.h"

class StmtLoop: public Statement{
private:
    Expression* condition;
    Statement* body;
public:
    StmtLoop(Expression *condition, Statement *body);

    void accept(Visitor *visitor) override;

    Expression *getCondition() const;

    Statement *getBody() const;
};


#endif //K_LANG_STMTLOOP_H
