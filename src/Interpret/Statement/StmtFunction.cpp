#include "StmtFunction.h"
#include "../KFunction.h"

StmtFunction::StmtFunction(IdToken *name, const std::vector<IdToken *> &params, StmtBlock *body) : name(name),
                                                                                                 params(params),
                                                                                                 body(body) {}

void StmtFunction::execute(Environment* environment) {
    KFunction* function = new KFunction(this, environment, false);
    TData dataFunction = TData(function);
    environment->define(name, dataFunction);
}

std::vector<IdToken *> StmtFunction::getParams() {
    return params;
}

StmtBlock* StmtFunction::getBody(){
    return body;
}
