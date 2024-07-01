#include "ExprUnary.h"

ExprUnary::ExprUnary(Expression *left, Token *oper) : left(left), oper(oper) {}

KData ExprUnary::accept(VisitorExpression *visitor) {
    return visitor->visitUnaryExpr(this);
}

Expression *ExprUnary::getLeft() const {
    return left;
}

Token *ExprUnary::getOper() const {
    return oper;
}
