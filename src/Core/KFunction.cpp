#include "KFunction.h"
#include "Return.h"

KFunction::KFunction(StmtFunction *declaration, Environment *closure, bool isInitializer) : declaration(
        declaration), closure(closure), isInitializer(isInitializer) {}

int KFunction::arity() {
    return declaration->getParams().size();
}

KData KFunction::call(Environment* environment, std::vector<KData> arguments) {

    Environment* localEenvironment = new Environment(closure);

    for (int i = 0; i < declaration->getParams().size(); i++) {
        localEenvironment->define(declaration->getParams().at(i), arguments.at(i));
    }

    try{
        //declaration->getBody()->execute(localEenvironment);
    }
    catch (Return returnValue){
        return returnValue.getValue();
    }

    // Pendiente atrapar el return;

    /*try {
        interpreter.executeBlock(declaration.body, environment);
    } catch (Return returnValue) {
        if (isInitializer) return closure.getAt(0, "this");
        return returnValue.value;
    }

    if (isInitializer) return closure.getAt(0, "this");
    return null;*/

    return KData();
}

std::string KFunction::toString() {
    return "<fn " + declaration->getName()->getIdentifier() + ">";
}
