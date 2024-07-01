#include "ExprLogical.h"

ExprLogical::ExprLogical(Expression *left, Token *oper, Expression *right) : left(left), oper(oper), right(right) {}

KData ExprLogical::accept(Visitor *visitor) {
    return visitor->visitLogicalExpr(this);
}

Expression *ExprLogical::getLeft() const {
    return left;
}

Token *ExprLogical::getOper() const {
    return oper;
}

Expression *ExprLogical::getRight() const {
    return right;
}
