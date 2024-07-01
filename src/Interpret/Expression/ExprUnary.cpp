#include "ExprUnary.h"

ExprUnary::ExprUnary(Expression *left, Token *oper) : left(left), oper(oper) {}

void ExprUnary::accept(Visitor *visitor) {
    visitor->visitUnaryExpr(this);
}

Expression *ExprUnary::getLeft() const {
    return left;
}

Token *ExprUnary::getOper() const {
    return oper;
}
