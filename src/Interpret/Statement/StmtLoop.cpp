#include "StmtLoop.h"
#include "../../Exceptions/RuntimeException.h"

StmtLoop::StmtLoop(Expression *condition, Statement *body) : condition(condition), body(body) {}

void StmtLoop::accept(Visitor *visitor) {
    visitor->visitLoopStmt(this);
}
