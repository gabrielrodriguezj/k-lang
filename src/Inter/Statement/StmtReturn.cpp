#include "StmtReturn.h"
#include "../../Exceptions/NotImplementedYetException.h"

StmtReturn::StmtReturn(Expression *expression) : expression(expression) {}

void StmtReturn::execute(Environment* environment) {
    throw NotImplementedYetException("Not implemented yet");
}