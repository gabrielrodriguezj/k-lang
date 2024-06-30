#include "StmtIf.h"
#include "../../Exceptions/RuntimeException.h"

StmtIf::StmtIf(Expression *condition, Statement *thenBranch, Statement *elseBranch) : condition(condition),
                                                                                      thenBranch(thenBranch),
                                                                                      elseBranch(elseBranch) {}

void StmtIf::accept(Visitor *visitor) {
    visitor->visitIfStmt(this);
}
