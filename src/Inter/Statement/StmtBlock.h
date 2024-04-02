#ifndef K_LANG_STMTBLOCK_H
#define K_LANG_STMTBLOCK_H


#include <list>
#include "Statement.h"
#include "../Environment.h"

class StmtBlock: public Statement{
private:
    std::list<Statement*> statements;

public:
    explicit StmtBlock(const std::list<Statement *> &statements);

    void execute(Environment*) override;
};


#endif //K_LANG_STMTBLOCK_H
