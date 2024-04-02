#include "ExprVariable.h"

ExprVariable::ExprVariable(Token *name) : name(name) {}

Object ExprVariable::solve() {
    // Not implemented yet
}

Token* ExprVariable::getName() {
    return name;
}