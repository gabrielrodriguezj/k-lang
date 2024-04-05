#include "ExprCallFunction.h"
#include "../../Exceptions/RuntimeException.h"

ExprCallFunction::ExprCallFunction(Expression *callee, std::list<Expression*> arguments) : callee(callee),
                                                                                           arguments(arguments) {}

TData ExprCallFunction::solve(Environment* environment) {
    TData calleeResult = callee->solve(environment);

    std::list<TData> args;
    for (Expression *argument: this->arguments) {
        TData result = argument->solve(environment);
        args.push_back(result);
    }

    if (!std::holds_alternative<KCallable*>(calleeResult.getValue()) ) {
        throw new RuntimeException("La expresion no corresponde a una llamada valida.");
    }

    KCallable *function = std::get<KCallable*>(calleeResult.getValue());
    return function->call(environment, args);
}

