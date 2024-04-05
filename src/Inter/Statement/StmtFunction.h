#ifndef K_LANG_STMTFUNCTION_H
#define K_LANG_STMTFUNCTION_H


#include <vector>
#include "Statement.h"
#include "../../Token/IdToken.h"
#include "StmtBlock.h"

class StmtFunction: public Statement{
private:
    IdToken* name;
    std::vector<IdToken*> params;
    StmtBlock* body;
public:
    StmtFunction(IdToken *name, const std::vector<IdToken *> &params, StmtBlock *body);
    void execute(Environment*) override;
    std::vector<IdToken*> getParams();
    StmtBlock* getBody();
};


#endif //K_LANG_STMTFUNCTION_H
