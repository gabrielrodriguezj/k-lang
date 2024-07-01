#include "StmtPrint.h"
#include "../KFunction.h"

StmtPrint::StmtPrint(Expression *expression) : expression(expression) {}

void StmtPrint::accept(VisitorStatement *visitor) {
    visitor->visitPrintStmt(this);
}

Expression *StmtPrint::getExpression() const {
    return expression;
}
