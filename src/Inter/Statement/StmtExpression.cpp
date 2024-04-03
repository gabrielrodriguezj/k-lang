#include "StmtExpression.h"
#include "../../Exceptions/NotImplementedYetException.h"

StmtExpression::StmtExpression(Expression *expression) : expression(expression) {}

void StmtExpression::execute(Environment* environment) {
    throw NotImplementedYetException("Not implemented yet");
}
