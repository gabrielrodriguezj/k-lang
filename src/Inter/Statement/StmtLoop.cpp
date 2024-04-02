#include "StmtLoop.h"

StmtLoop::StmtLoop(Expression *condition, Statement *body) : condition(condition), body(body) {}

void StmtLoop::execute(Environment* environment) {

}
