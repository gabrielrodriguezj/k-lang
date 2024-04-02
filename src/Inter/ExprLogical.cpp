#include "ExprLogical.h"

ExprLogical::ExprLogical(Expression *left, Token *oper, Expression *right) : left(left), oper(oper), right(right) {}

TType ExprLogical::solve() {
    // Not implemented yet
    return TType();
}