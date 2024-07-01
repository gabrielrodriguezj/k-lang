#include "ExprArithmetic.h"

ExprArithmetic::ExprArithmetic(Expression *left, Token *oper, Expression *right) : left(left), oper(oper), right(right) {}

KData ExprArithmetic::accept(Visitor *visitor) {
    return visitor->visitArithmeticExpr(this);
}

Expression *ExprArithmetic::getLeft() const {
    return left;
}

Token *ExprArithmetic::getOper() const {
    return oper;
}

Expression *ExprArithmetic::getRight() const {
    return right;
}
