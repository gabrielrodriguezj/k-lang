#include "StmtIf.h"
#include "../../Exceptions/NotImplementedYetException.h"

StmtIf::StmtIf(Expression *condition, Statement *thenBranch, Statement *elseBranch) : condition(condition),
                                                                                      thenBranch(thenBranch),
                                                                                      elseBranch(elseBranch) {}

void StmtIf::execute(Environment* environment) {
    throw NotImplementedYetException("Not implemented yet");
}
