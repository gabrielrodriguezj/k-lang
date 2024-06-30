#include "StmtClass.h"
#include "../../Exceptions/NotImplementedYetException.h"

StmtClass::StmtClass(IdToken *name, ExprVariable *superclass, const std::vector<StmtFunction *> &methods,
                     const std::vector<StmtVariable *> &variables) : name(name), superclass(superclass), methods(methods),
                                                                   variables(variables) {}

void StmtClass::execute(Environment* environment) {
    throw NotImplementedYetException("Not implemented yet");
}

void StmtClass::accept(Visitor *visitor) const {
    visitor->visitClassStmt(this);
}
