#include "StmtFunction.h"
#include "../../Exceptions/NotImplementedYetException.h"

StmtFunction::StmtFunction(IdToken *name, const std::list<IdToken *> &params, StmtBlock *body) : name(name),
                                                                                                 params(params),
                                                                                                 body(body) {}

void StmtFunction::execute(Environment* environment) {
    throw NotImplementedYetException("Not implemented yet");
}

std::list<IdToken *> StmtFunction::getParams() {
    return params;
}
