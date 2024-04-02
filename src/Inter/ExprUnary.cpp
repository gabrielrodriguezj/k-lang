#include "ExprUnary.h"

ExprUnary::ExprUnary(Expression *left, Token *oper) : left(left), oper(oper) {}

TType ExprUnary::solve() {
    // Not implemented yet
    return TType();
}
