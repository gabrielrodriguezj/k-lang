#include "StmtVariable.h"

StmtVariable::StmtVariable(IdToken *name, Expression *initializer) : name(name), initializer(initializer) {}

void StmtVariable::execute(Environment* environment) {
    TData value;
    if(initializer != nullptr){
        value = initializer->solve(environment);
    }

    environment->define(name, value);
}

void StmtVariable::accept(Visitor *visitor) const {
    visitor->visitVarStmt(this);
}
