#include "ExprGrouping.h"

ExprGrouping::ExprGrouping(Expression* expression) : expression(expression){}

Object ExprGrouping::solve() {
    return expression->solve();
}