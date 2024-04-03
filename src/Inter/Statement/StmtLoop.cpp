#include "StmtLoop.h"
#include "../../Exceptions/NotImplementedYetException.h"

StmtLoop::StmtLoop(Expression *condition, Statement *body) : condition(condition), body(body) {}

void StmtLoop::execute(Environment* environment) {
    throw NotImplementedYetException("Not implemented yet");
}
