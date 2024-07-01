#include "StmtLoop.h"
#include "../../Exceptions/RuntimeException.h"

StmtLoop::StmtLoop(Expression *condition, Statement *body) : condition(condition), body(body) {}

void StmtLoop::accept(VisitorStatement *visitor) {
    visitor->visitLoopStmt(this);
}

Expression *StmtLoop::getCondition() const {
    return condition;
}

Statement *StmtLoop::getBody() const {
    return body;
}
