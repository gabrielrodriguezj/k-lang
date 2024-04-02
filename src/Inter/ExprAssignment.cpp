#include "ExprAssignment.h"

ExprAssignment::ExprAssignment(IdToken *name, Expression *expression) : name(name), expression(expression) {}

TData ExprAssignment::solve() {
    // Not implemented yet
    return expression->solve();
}
