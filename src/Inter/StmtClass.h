#ifndef K_LANG_STMTCLASS_H
#define K_LANG_STMTCLASS_H


#include <list>
#include "../Token/Token.h"
#include "ExprVariable.h"
#include "Statement.h"
#include "StmtFunction.h"
#include "StmtVariable.h"
#include "../Token/IdToken.h"

class StmtClass: public Statement{
private:
    IdToken* name;
    ExprVariable* superclass;
    std::list<StmtFunction*> methods;
    std::list<StmtVariable*> variables;
public:
    StmtClass(IdToken *name, ExprVariable *superclass, const std::list<StmtFunction *> &methods,
              const std::list<StmtVariable *> &variables);

    void execute() override;
};


#endif //K_LANG_STMTCLASS_H
