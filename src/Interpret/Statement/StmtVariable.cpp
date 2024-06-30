#include "StmtVariable.h"

StmtVariable::StmtVariable(IdToken *name, Expression *initializer) : name(name), initializer(initializer) {}

void StmtVariable::accept(Visitor *visitor) const {
    //visitor->visitVarStmt(this);
}
