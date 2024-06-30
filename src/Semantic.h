#ifndef K_LANG_SEMANTIC_H
#define K_LANG_SEMANTIC_H

#include <iostream>
#include "Interpret/Statement/Statement.h"

class Semantic: public Visitor{
public:
    explicit Semantic(const std::vector<Statement *> &statements);
    void analyse();
private:
    std::vector<Statement*> statements;

    void resolve(const std::vector<Statement *> &statements);

    void visitBlockStmt(StmtBlock *stmt);
};


#endif //K_LANG_SEMANTIC_H
