#include "ExprAssignment.h"
#include "../../Exceptions/NotImplementedYetException.h"

ExprAssignment::ExprAssignment(IdToken *name, Expression *expression) : name(name), expression(expression) {}

TData ExprAssignment::solve(Environment* environment) {
    throw NotImplementedYetException("Not implemented yet");
}
