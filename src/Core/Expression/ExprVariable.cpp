#include "ExprVariable.h"

ExprVariable::ExprVariable(IdToken *name) : name(name) {}

IdToken* ExprVariable::getName() {
    return name;
}

KData ExprVariable::accept(VisitorExpression *visitor) {
    return visitor->visitVariableExpr(this);
}
