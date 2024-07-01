#include "StmtReturn.h"
#include "../Return.h"

StmtReturn::StmtReturn(Token *keyword, Expression *value) : keyword(keyword), value(value) {}

void StmtReturn::accept(Visitor *visitor) {
    visitor->visitReturnStmt(this);
}

Token *StmtReturn::getKeyword() const {
    return keyword;
}

Expression *StmtReturn::getValue() const {
    return value;
}
