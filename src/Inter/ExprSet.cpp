#include "ExprSet.h"

ExprSet::ExprSet(Expression *object, Token *name, Expression *value) : object(object), name(name), value(value) {}

TType ExprSet::solve() {
    //Not implemented yet
    return TType();
}
