#include "KFunction.h"

KFunction::KFunction(StmtFunction *declaration, const Environment &closure, bool isInitializer) : declaration(
        declaration), closure(closure), isInitializer(isInitializer) {}

int KFunction::arity() {
    return declaration->getParams().size();
}

TData KFunction::call(Environment* environment, std::vector<TData> arguments) {

    Environment* localEenvironment = new Environment(closure);

    for (int i = 0; i < declaration->getParams().size(); i++) {
        localEenvironment->define(declaration->getParams().at(i), arguments.at(i));
    }

    return TData();
}
