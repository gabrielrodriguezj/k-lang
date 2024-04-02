#include "StmtFunction.h"

StmtFunction::StmtFunction(IdToken *name, const std::list<IdToken *> &params, StmtBlock *body) : name(name),
                                                                                                 params(params),
                                                                                                 body(body) {}

void StmtFunction::execute(Environment* environment) {

}
