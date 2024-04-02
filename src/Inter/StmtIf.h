#ifndef K_LANG_STMTIF_H
#define K_LANG_STMTIF_H


#include "Statement.h"
#include "Expression.h"

class StmtIf: public Statement{
private:
    Expression* condition;
    Statement* thenBranch;
    Statement* elseBranch;
public:
    StmtIf(Expression *condition, Statement *thenBranch, Statement *elseBranch);
    void execute() override;
};


#endif //K_LANG_STMTIF_H
