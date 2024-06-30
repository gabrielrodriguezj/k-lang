#ifndef K_LANG_STMTCLASS_H
#define K_LANG_STMTCLASS_H


#include <vector>
#include "../../Token/Token.h"
#include "../Expression/ExprVariable.h"
#include "Statement.h"
#include "StmtFunction.h"
#include "StmtVariable.h"
#include "../../Token/IdToken.h"

class StmtClass: public Statement{
private:
    IdToken* name;
    ExprVariable* superclass;
    std::vector<StmtFunction*> methods;
    std::vector<StmtVariable*> variables;
public:
    StmtClass(IdToken *name, ExprVariable *superclass, const std::vector<StmtFunction *> &methods,
              const std::vector<StmtVariable *> &variables);

    void execute(Environment*) override;

    void accept(Visitor *visitor) const override;
};


#endif //K_LANG_STMTCLASS_H
