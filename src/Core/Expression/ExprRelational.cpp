#include "ExprRelational.h"

ExprRelational::ExprRelational(Expression *left, Token *oper, Expression *right) : left(left), oper(oper), right(right) {}

void ExprRelational::accept(Visitor *visitor) {
    visitor->visitRelational(this);
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