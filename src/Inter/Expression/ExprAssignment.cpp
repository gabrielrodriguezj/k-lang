#include "ExprAssignment.h"

ExprAssignment::ExprAssignment(IdToken *name, Expression *expression) : name(name), expression(expression) {}

TData ExprAssignment::solve(Environment* environment) {
    TData value = expression->solve(environment);
    environment->assign(name, value);
    return TData();
}
