#include "ExprVariable.h"

ExprVariable::ExprVariable(TToken *name) : name(name) {}

std::variant<std::monostate, int, double, bool, std::string> ExprVariable::solve() {
    // Not implemented yet
    return 0;
}
