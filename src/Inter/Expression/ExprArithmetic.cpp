#include "ExprArithmetic.h"

ExprArithmetic::ExprArithmetic(Expression *left, Token *oper, Expression *right) : left(left), oper(oper), right(right) {}

TData ExprArithmetic::solve(Environment* environment) {
    // Not implemented yet
}
