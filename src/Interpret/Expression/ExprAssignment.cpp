#include "ExprAssignment.h"

ExprAssignment::ExprAssignment(IdToken *name, Expression *expression) : name(name), expression(expression) {}

void ExprAssignment::accept(Visitor *visitor) {
    visitor->visitAssignExpr(this);
}

