#include "ExprAssignment.h"

ExprAssignment::ExprAssignment(Token *name, Expression *expression) : name(name), expression(expression) {}

std::variant<std::monostate, int, double, bool, std::string> ExprAssignment::solve() {
    // Not implemented yet
    return expression->solve();
}
