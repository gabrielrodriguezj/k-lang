#include "ExprGrouping.h"

ExprGrouping::ExprGrouping(Expression* expression) : expression(expression){}

TData ExprGrouping::solve(Environment* environment) {
    return expression->solve(environment);
}