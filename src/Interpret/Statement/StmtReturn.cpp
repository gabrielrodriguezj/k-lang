#include "StmtReturn.h"
#include "../Return.h"

StmtReturn::StmtReturn(Token *keyword, Expression *value) : keyword(keyword), value(value) {}

void StmtReturn::accept(Visitor *visitor) const {
    //visitor->visitReturnStmt(this);
}
