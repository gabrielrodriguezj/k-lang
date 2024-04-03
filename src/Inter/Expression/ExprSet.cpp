#include "ExprSet.h"
#include "../../Exceptions/NotImplementedYetException.h"

ExprSet::ExprSet(Expression *object, Token *name, Expression *value) : object(object), name(name), value(value) {}

TData ExprSet::solve(Environment* environment) {
    throw NotImplementedYetException("Not implemented yet");
}
