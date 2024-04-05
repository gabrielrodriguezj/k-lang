#include "StmtExpression.h"

StmtExpression::StmtExpression(Expression *expression) : expression(expression) {}

void StmtExpression::execute(Environment* environment) {
    expression->solve(environment);
}