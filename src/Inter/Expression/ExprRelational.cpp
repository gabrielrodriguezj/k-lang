#include "ExprRelational.h"

ExprRelational::ExprRelational(Expression *left, Token *oper, Expression *right) : left(left), oper(oper), right(right) {}

TData ExprRelational::solve(Environment* environment) {
    TData valueLeft = left->solve(environment);
    TData valueRight = right->solve(environment);

    if(oper->getName() == TokenName::LESS){
        return valueLeft < valueRight;
    }
    if(oper->getName() == TokenName::LESS_EQUAL){
        return valueLeft <= valueRight;
    }
    if(oper->getName() == TokenName::GREATER){
        return valueLeft > valueRight;
    }
    if(oper->getName() == TokenName::GREATER_EQUAL){
        return valueLeft >= valueRight;
    }
    if(oper->getName() == TokenName::BANG_EQUAL){
        return valueLeft != valueRight;
    }
    if(oper->getName() == TokenName::EQUAL_EQUAL){
        return valueLeft == valueRight;
    }
}