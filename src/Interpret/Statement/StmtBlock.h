#ifndef K_LANG_STMTBLOCK_H
#define K_LANG_STMTBLOCK_H


#include <vector>
#include "Statement.h"
#include "../Environment.h"

class visitor;

class StmtBlock: public Statement{
private:
    std::vector<Statement*> statements;

public:
    explicit StmtBlock(const std::vector<Statement *> &statements);

    void execute(Environment*) override;

    void accept(Visitor *visitor) const override;
};


#endif //K_LANG_STMTBLOCK_H
