#include "ExprVariable.h"

ExprVariable::ExprVariable(IdToken *name) : name(name) {}

TData ExprVariable::solve(Environment* environment) {
    return environment->get(name);
}

IdToken* ExprVariable::getName() {
    return name;
}