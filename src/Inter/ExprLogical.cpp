#include "ExprLogical.h"

ExprLogical::ExprLogical(Expression *left, Token *oper, Expression *right) : left(left), oper(oper), right(right) {}

std::variant<std::monostate, int, double, bool, std::string> ExprLogical::solve() {
    // Not implemented yet
    return 0;
}