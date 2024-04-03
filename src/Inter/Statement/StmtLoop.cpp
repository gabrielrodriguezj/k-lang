#include "StmtLoop.h"
#include "../../Exceptions/RuntimeException.h"

StmtLoop::StmtLoop(Expression *condition, Statement *body) : condition(condition), body(body) {}

void StmtLoop::execute(Environment* environment) {
    TData solCondition = condition->solve(environment);

    if (!std::holds_alternative<bool>(solCondition.getValue())) {
        throw RuntimeException("La condicion no es una expresion valida");
    }

    bool resCondition = std::get<bool>(solCondition.getValue());
    while (resCondition){
        body->execute(environment);

        // Evaluate the condition after execute the body
        solCondition = condition->solve(environment);
        if (!std::holds_alternative<bool>(solCondition.getValue())) {
            throw RuntimeException("La condicion no es una expresion valida");
        }
        resCondition = std::get<bool>(solCondition.getValue());
    }
}
