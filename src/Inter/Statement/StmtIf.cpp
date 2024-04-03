#include "StmtIf.h"
#include "../../Exceptions/RuntimeException.h"

StmtIf::StmtIf(Expression *condition, Statement *thenBranch, Statement *elseBranch) : condition(condition),
                                                                                      thenBranch(thenBranch),
                                                                                      elseBranch(elseBranch) {}

void StmtIf::execute(Environment* environment) {
    TData solCondition = condition->solve(environment);

    if (!std::holds_alternative<bool>(solCondition.getValue())) {
        throw RuntimeException("La condicion no es una expresion valida");
    }

    bool resCondition = std::get<bool>(solCondition.getValue());
    if(resCondition){
        thenBranch->execute(environment);
        return;
    }

    if(elseBranch != nullptr){
        elseBranch->execute(environment);
    }
    
}
