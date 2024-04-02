#include "ExprVariable.h"

ExprVariable::ExprVariable(Token *name) : name(name) {}

TData ExprVariable::solve() {
    // Not implemented yet
}

Token* ExprVariable::getName() {
    return name;
}