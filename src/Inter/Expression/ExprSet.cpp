#include "ExprSet.h"

ExprSet::ExprSet(Expression *object, Token *name, Expression *value) : object(object), name(name), value(value) {}

TData ExprSet::solve(Environment* environment) {
    //Not implemented yet
}