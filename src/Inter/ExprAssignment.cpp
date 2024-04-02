#include "ExprAssignment.h"

ExprAssignment::ExprAssignment(Token *name, Expression *expression) : name(name), expression(expression) {}

TData ExprAssignment::solve() {
    // Not implemented yet
    return expression->solve();
}
