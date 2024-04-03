#include "StmtClass.h"
#include "../../Exceptions/NotImplementedYetException.h"

StmtClass::StmtClass(IdToken *name, ExprVariable *superclass, const std::list<StmtFunction *> &methods,
                     const std::list<StmtVariable *> &variables) : name(name), superclass(superclass), methods(methods),
                                                                   variables(variables) {}

void StmtClass::execute(Environment* environment) {
    throw NotImplementedYetException("Not implemented yet");
}
