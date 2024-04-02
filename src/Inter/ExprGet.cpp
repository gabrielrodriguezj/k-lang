#include "ExprGet.h"

ExprGet::ExprGet(Expression *object, Token *name) : object(object), name(name) {}

Object ExprGet::solve() {
    // Not implemented yet
}

Expression* ExprGet::getObject(){
    return object;
}

Token* ExprGet::getName(){
    return name;
}
