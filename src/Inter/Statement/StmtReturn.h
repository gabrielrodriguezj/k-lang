#ifndef K_LANG_STMTRETURN_H
#define K_LANG_STMTRETURN_H


#include "Statement.h"
#include "../Expression/Expression.h"

class StmtReturn: public Statement{
private:
    Expression* expression;
public:
    explicit StmtReturn(Expression *expression);

    void execute(Environment*) override;
};


#endif //K_LANG_STMTRETURN_H
