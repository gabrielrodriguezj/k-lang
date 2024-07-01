#ifndef K_LANG_STMTIF_H
#define K_LANG_STMTIF_H


#include "Statement.h"
#include "../Expression/Expression.h"

class StmtIf: public Statement{
private:
    Expression* condition;
    Statement* thenBranch;
    Statement* elseBranch;
public:
    StmtIf(Expression *condition, Statement *thenBranch, Statement *elseBranch);

    void accept(VisitorStatement *visitor) override;

    Expression *getCondition() const;

    Statement *getThenBranch() const;

    Statement *getElseBranch() const;
};


#endif //K_LANG_STMTIF_H
