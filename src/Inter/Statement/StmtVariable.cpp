#include "StmtVariable.h"
#include "../../Exceptions/NotImplementedYetException.h"

StmtVariable::StmtVariable(IdToken *name, Expression *initializer) : name(name), initializer(initializer) {}

void StmtVariable::execute(Environment* environment) {
    throw NotImplementedYetException("Not implemented yet");
}
