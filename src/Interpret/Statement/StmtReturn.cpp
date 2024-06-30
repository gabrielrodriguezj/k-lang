#include "StmtReturn.h"
#include "../Return.h"

StmtReturn::StmtReturn(Token *keyword, Expression *value) : keyword(keyword), value(value) {}

void StmtReturn::execute(Environment* environment) {
    TData valueReturn;

    if(value != nullptr){
        valueReturn = value->solve(environment);
    }

    throw Return("Return", valueReturn);
}

void StmtReturn::accept(Visitor *visitor) const {
    visitor->visitReturnStmt(this);
}
