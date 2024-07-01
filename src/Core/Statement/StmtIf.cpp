#include "StmtIf.h"
#include "../../Exceptions/RuntimeException.h"

StmtIf::StmtIf(Expression *condition, Statement *thenBranch, Statement *elseBranch) : condition(condition),
                                                                                      thenBranch(thenBranch),
                                                                                      elseBranch(elseBranch) {}

void StmtIf::accept(VisitorStatement *visitor) {
    visitor->visitIfStmt(this);
}

Expression *StmtIf::getCondition() const {
    return condition;
}

Statement *StmtIf::getThenBranch() const {
    return thenBranch;
}

Statement *StmtIf::getElseBranch() const {
    return elseBranch;
}
