#include "ExprArithmetic.h"

ExprArithmetic::ExprArithmetic(Expression *left, Token *oper, Expression *right) : left(left), oper(oper), right(right) {}

TType ExprArithmetic::solve() {
    // Not implemented yet
    return TType();
}
