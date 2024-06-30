#include "StmtFunction.h"
#include "../KFunction.h"

StmtFunction::StmtFunction(IdToken *name, const std::vector<IdToken *> &params, StmtBlock *body) : name(name),
                                                                                                 params(params),
                                                                                                 body(body) {}

std::vector<IdToken *> StmtFunction::getParams() {
    return params;
}

StmtBlock* StmtFunction::getBody(){
    return body;
}

IdToken* StmtFunction::getName(){
    return name;
}

void StmtFunction::accept(Visitor *visitor) const {
    //visitor->visitFunctionStmt(this);
}
