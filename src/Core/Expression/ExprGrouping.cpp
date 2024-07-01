#include "ExprGrouping.h"

ExprGrouping::ExprGrouping(Expression* expression) : expression(expression){}

KData ExprGrouping::accept(VisitorExpression *visitor) {
    return visitor->visitGroupingExpr(this);
}

Expression *ExprGrouping::getExpression() const {
    return expression;
}
