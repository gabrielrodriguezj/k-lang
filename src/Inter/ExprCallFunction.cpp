#include "ExprCallFunction.h"

ExprCallFunction::ExprCallFunction(Expression *callee, std::list<Expression> *arguments) : callee(callee),
                                                                                           arguments(arguments) {}

TType ExprCallFunction::solve() {
    // Not implemented yet
    return TType();
}

