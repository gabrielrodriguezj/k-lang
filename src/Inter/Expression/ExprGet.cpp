#include "ExprGet.h"
#include "../../Exceptions/NotImplementedYetException.h"

ExprGet::ExprGet(Expression *object, Token *name) : object(object), name(name) {}

TData ExprGet::solve(Environment* environment) {
    throw NotImplementedYetException("Not implemented yet");
}

Expression* ExprGet::getObject(){
    return object;
}

Token* ExprGet::getName(){
    return name;
}
