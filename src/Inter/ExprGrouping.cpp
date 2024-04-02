#include "ExprGrouping.h"

ExprGrouping::ExprGrouping(Expression* expression) : expression(expression){}

TType ExprGrouping::solve() {
    return expression->solve();
}