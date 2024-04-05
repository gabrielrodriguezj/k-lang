#include "StmtFunction.h"
#include "../../Exceptions/NotImplementedYetException.h"

StmtFunction::StmtFunction(IdToken *name, const std::vector<IdToken *> &params, StmtBlock *body) : name(name),
                                                                                                 params(params),
                                                                                                 body(body) {}

void StmtFunction::execute(Environment* environment) {
    throw NotImplementedYetException("Not implemented yet");
}

std::vector<IdToken *> StmtFunction::getParams() {
    return params;
}
