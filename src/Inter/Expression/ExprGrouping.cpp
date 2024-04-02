#include "ExprGrouping.h"

ExprGrouping::ExprGrouping(Expression* expression) : expression(expression){}

TData ExprGrouping::solve() {
    return expression->solve();
}