#include "StmtExpression.h"

StmtExpression::StmtExpression(Expression *expression) : expression(expression) {}

void StmtExpression::accept(VisitorStatement *visitor) {
    visitor->visitExpressionStmt(this);
}

Expression *StmtExpression::getExpression() {
    return expression;
}
