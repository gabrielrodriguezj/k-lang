#include "ExprGet.h"
#include "../../Exceptions/NotImplementedYetException.h"

ExprGet::ExprGet(Expression *object, Token *name) : object(object), name(name) {}

Expression* ExprGet::getObject(){
    return object;
}

Token* ExprGet::getName(){
    return name;
}

void ExprGet::accept(Visitor *visitor) const {

}
