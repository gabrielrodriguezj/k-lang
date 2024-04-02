#include "ExprGrouping.h"

ExprGrouping::ExprGrouping(Expression* expression) : expression(expression){}

std::variant<std::monostate, int, double, bool, std::string> ExprGrouping::solve() {
    return expression->solve();
}