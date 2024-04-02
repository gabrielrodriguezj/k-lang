#include "StmtIf.h"

StmtIf::StmtIf(Expression *condition, Statement *thenBranch, Statement *elseBranch) : condition(condition),
                                                                                      thenBranch(thenBranch),
                                                                                      elseBranch(elseBranch) {}

void StmtIf::execute(Environment* environment) {

}
