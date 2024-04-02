#include "ExprAssignment.h"

ExprAssignment::ExprAssignment(Token *name, Expression *expression) : name(name), expression(expression) {}

Object ExprAssignment::solve() {
    // Not implemented yet
    return expression->solve();
}
