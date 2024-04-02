#include "ExprCallFunction.h"

ExprCallFunction::ExprCallFunction(Expression *callee, std::list<Expression> *arguments) : callee(callee),
                                                                                           arguments(arguments) {}

std::variant<std::monostate, int, double, bool, std::string> ExprCallFunction::solve() {
    // Not implemented yet
    return 0;
}

