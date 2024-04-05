#ifndef K_LANG_STMTFUNCTION_H
#define K_LANG_STMTFUNCTION_H


#include <list>
#include "Statement.h"
#include "../../Token/IdToken.h"
#include "StmtBlock.h"

class StmtFunction: public Statement{
private:
    IdToken* name;
    std::list<IdToken*> params;
    StmtBlock* body;
public:
    StmtFunction(IdToken *name, const std::list<IdToken *> &params, StmtBlock *body);
    void execute(Environment*) override;
    std::list<IdToken*> getParams();
};


#endif //K_LANG_STMTFUNCTION_H
