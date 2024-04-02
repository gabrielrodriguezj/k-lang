#include "ExprGet.h"

ExprGet::ExprGet(Expression *object, Token *name) : object(object), name(name) {}

std::variant<std::monostate, int, double, bool, std::string> ExprGet::solve() {
    // Not implemented yet
    return 0;
}
