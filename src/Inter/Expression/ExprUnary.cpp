#include "ExprUnary.h"

ExprUnary::ExprUnary(Expression *left, Token *oper) : left(left), oper(oper) {}

TData ExprUnary::solve(Environment* environment) {
    // Not implemented yet
}
