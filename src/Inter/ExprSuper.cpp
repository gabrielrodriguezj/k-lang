#include "ExprSuper.h"

ExprSuper::ExprSuper(Token *method) : method(method) {}

std::variant<std::monostate, int, double, bool, std::string> ExprSuper::solve() {
    // Not implemented yet
    return 0;
}
