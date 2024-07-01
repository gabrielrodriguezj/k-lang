#ifndef K_LANG_STMTFUNCTION_H
#define K_LANG_STMTFUNCTION_H


#include <vector>
#include "Statement.h"

class VisitorExpression;


class StmtFunction: public Statement{
private:
    IdToken* name;
    std::vector<IdToken*> params;
    StmtBlock* body;
public:
    StmtFunction(IdToken *name, const std::vector<IdToken *> &params, StmtBlock *body);
    std::vector<IdToken*> getParams();
    StmtBlock* getBody();
    IdToken* getName();

    void accept(VisitorStatement *visitor) override;
};


#endif //K_LANG_STMTFUNCTION_H
