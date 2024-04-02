#include "ExprArithmetic.h"

ExprArithmetic::ExprArithmetic(Expression *left, Token *oper, Expression *right) : left(left), oper(oper), right(right) {}

Object ExprArithmetic::solve() {
    // Not implemented yet
}
