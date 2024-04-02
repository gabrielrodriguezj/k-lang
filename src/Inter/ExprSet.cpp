#include "ExprSet.h"

ExprSet::ExprSet(Expression *object, Token *name, Expression *value) : object(object), name(name), value(value) {}

std::variant<std::monostate, int, double, bool, std::string> ExprSet::solve() {
    //Not implemented yet
    return 0;
}
