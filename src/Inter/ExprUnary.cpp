#include "ExprUnary.h"

ExprUnary::ExprUnary(Expression *left, Token *oper) : left(left), oper(oper) {}

Object ExprUnary::solve() {
    // Not implemented yet
}
