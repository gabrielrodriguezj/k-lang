#ifndef K_LANG_STMTBLOCK_H
#define K_LANG_STMTBLOCK_H


#include <vector>
#include "Statement.h"

class VisitorExpression;

class StmtBlock: public Statement{
private:
    std::vector<Statement*> statements;

public:
    explicit StmtBlock(const std::vector<Statement *> &statements);

    void accept(VisitorStatement *visitor) override;

    std::vector<Statement *> getStatements();
};


#endif //K_LANG_STMTBLOCK_H
