#include "ExprRelational.h"

ExprRelational::ExprRelational(Expression *left, Token *oper, Expression *right) : left(left), oper(oper), right(right) {}

TType ExprRelational::solve() {
    // Not implemented yet
    return TType();
}