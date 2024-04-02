#include "ExprRelational.h"

ExprRelational::ExprRelational(Expression *left, Token *oper, Expression *right) : left(left), oper(oper), right(right) {}

std::variant<std::monostate, int, double, bool, std::string> ExprRelational::solve() {
    // Not implemented yet
    return 0;
}