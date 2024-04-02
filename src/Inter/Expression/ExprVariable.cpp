#include "ExprVariable.h"

ExprVariable::ExprVariable(IdToken *name) : name(name) {}

TData ExprVariable::solve(Environment* environment) {
    // Not implemented yet
}

IdToken* ExprVariable::getName() {
    return name;
}