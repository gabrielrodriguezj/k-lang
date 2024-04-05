#include "ExprUnary.h"

ExprUnary::ExprUnary(Expression *left, Token *oper) : left(left), oper(oper) {}

TData ExprUnary::solve(Environment* environment) {
    TData valueLeft = left->solve(environment);

    if(oper->getName() == TokenName::MINUS){
        return -valueLeft;
    }
    if(oper->getName() == TokenName::BANG){
        return !valueLeft;
    }
}
