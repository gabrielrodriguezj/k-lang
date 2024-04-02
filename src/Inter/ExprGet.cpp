#include "ExprGet.h"

ExprGet::ExprGet(Expression *object, Token *name) : object(object), name(name) {}

TType ExprGet::solve() {
    // Not implemented yet
    return TType();
}
