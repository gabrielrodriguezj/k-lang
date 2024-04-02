#include "ExprCallFunction.h"

ExprCallFunction::ExprCallFunction(Expression *callee, std::list<Expression*> arguments) : callee(callee),
                                                                                           arguments(arguments) {}

Object ExprCallFunction::solve() {
    // Not implemented yet
}

