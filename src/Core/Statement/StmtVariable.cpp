#include "StmtVariable.h"

StmtVariable::StmtVariable(IdToken *name, Expression *initializer) : name(name), initializer(initializer) {}

void StmtVariable::accept(VisitorStatement *visitor) {
    visitor->visitVarStmt(this);
}

IdToken *StmtVariable::getName() const {
    return name;
}

Expression *StmtVariable::getInitializer() const {
    return initializer;
}
