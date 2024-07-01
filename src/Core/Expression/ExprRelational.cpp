#include "ExprRelational.h"

ExprRelational::ExprRelational(Expression *left, Token *oper, Expression *right) : left(left), oper(oper), right(right) {}

KData ExprRelational::accept(Visitor *visitor) {
    return visitor->visitRelational(this);
}


Expression *ExprRelational::getLeft() const {
    return left;
}

Token *ExprRelational::getOper() const {
    return oper;
}

Expression *ExprRelational::getRight() const {
    return right;
}