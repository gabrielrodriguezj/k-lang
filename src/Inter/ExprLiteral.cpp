#include "ExprLiteral.h"

ExprLiteral::ExprLiteral(std::variant<std::monostate, int, double, bool, std::string> value): value(value){}
ExprLiteral::ExprLiteral(){}

TData ExprLiteral::solve() {
    // Not implemented yet
}