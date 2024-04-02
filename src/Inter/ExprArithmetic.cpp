#include "ExprArithmetic.h"

ExprArithmetic::ExprArithmetic(Expression *left, Token *oper, Expression *right) : left(left), oper(oper), right(right) {}

std::variant<std::monostate, int, double, bool, std::string> ExprArithmetic::solve() {
    // Not implemented yet
    return 0;
}
