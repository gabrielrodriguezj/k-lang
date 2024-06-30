#include "ExprLogical.h"

ExprLogical::ExprLogical(Expression *left, Token *oper, Expression *right) : left(left), oper(oper), right(right) {}

TData ExprLogical::solve(Environment *environment) {
    TData valueLeft = left->solve(environment);
    TData valueRight = right->solve(environment);

    if(oper->getName() == TokenName::OR){
        return valueLeft || valueRight;
    }

    if(oper->getName() == TokenName::AND){
        return valueLeft && valueRight;
    }

    return TData();
}
