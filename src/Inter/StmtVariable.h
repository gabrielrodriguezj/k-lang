#ifndef K_LANG_STMTVARIABLE_H
#define K_LANG_STMTVARIABLE_H


#include "Statement.h"
#include "../Token/IdToken.h"
#include "Expression.h"

class StmtVariable: public Statement{
private:
    IdToken* name;
    Expression* initializer;
public:
    StmtVariable(IdToken *name, Expression *initializer);
    void execute() override;
};


#endif //K_LANG_STMTVARIABLE_H
