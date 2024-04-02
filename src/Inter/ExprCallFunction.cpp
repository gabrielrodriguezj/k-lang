#include "ExprCallFunction.h"

ExprCallFunction::ExprCallFunction(Expression *callee, std::list<Expression*> arguments) : callee(callee),
                                                                                           arguments(arguments) {}

TData ExprCallFunction::solve() {
    // Not implemented yet
}

