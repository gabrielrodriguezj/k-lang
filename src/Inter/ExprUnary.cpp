#include "ExprUnary.h"

ExprUnary::ExprUnary(Expression *left, Token *oper) : left(left), oper(oper) {}

std::variant<std::monostate, int, double, bool, std::string> ExprUnary::solve() {
    // Not implemented yet
    return 0;
}
