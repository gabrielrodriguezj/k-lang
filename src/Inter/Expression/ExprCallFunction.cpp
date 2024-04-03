#include "ExprCallFunction.h"
#include "../../Exceptions/NotImplementedYetException.h"

ExprCallFunction::ExprCallFunction(Expression *callee, std::list<Expression*> arguments) : callee(callee),
                                                                                           arguments(arguments) {}

TData ExprCallFunction::solve(Environment* environment) {
    throw NotImplementedYetException("Not implemented yet");
}

