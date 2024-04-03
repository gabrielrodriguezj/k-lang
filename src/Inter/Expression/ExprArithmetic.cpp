#include "ExprArithmetic.h"

ExprArithmetic::ExprArithmetic(Expression *left, Token *oper, Expression *right) : left(left), oper(oper), right(right) {}

TData ExprArithmetic::solve(Environment* environment) {
    TData valueLeft = left->solve(environment);
    TData valueRight = right->solve(environment);

    if(oper->getName() == TokenName::PLUS){
        return valueLeft + valueRight;
    }
    if(oper->getName() == TokenName::MINUS){
        return valueLeft - valueRight;
    }
    if(oper->getName() == TokenName::STAR){
        return valueLeft * valueRight;
    }
    if(oper->getName() == TokenName::SLASH){
        return valueLeft / valueRight;
    }
}
