#include "ExprAssignment.h"

ExprAssignment::ExprAssignment(IdToken *name, Expression *expression) : name(name), expression(expression) {}

void ExprAssignment::accept(Visitor *visitor) {
    visitor->visitAssignExpr(this);
}

IdToken *ExprAssignment::getName() const {
    return name;
}

Expression *ExprAssignment::getExpression() const {
    return expression;
}
