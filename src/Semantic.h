#ifndef K_LANG_SEMANTIC_H
#define K_LANG_SEMANTIC_H

#include "Core/Statement/Statement.h"
#include "Core/Expression/VisitorExpression.h"
#include "Core/Statement/VisitorStatement.h"


class Semantic: public VisitorExpression, VisitorStatement{
public:
    explicit Semantic(const std::vector<Statement *> &statements);
    void analyse();
private:
    std::vector<Statement*> statements;
};


#endif //K_LANG_SEMANTIC_H
