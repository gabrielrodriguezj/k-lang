#include "StmtPrint.h"
#include "../KFunction.h"

StmtPrint::StmtPrint(Expression *expression) : expression(expression) {}

void StmtPrint::accept(Visitor *visitor) const {
    //visitor->
}
