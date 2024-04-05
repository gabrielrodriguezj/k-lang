#include "Interpreter.h"
#include "../Exceptions/RuntimeException.h"

Interpreter::Interpreter() {
    globals = new Environment(nullptr);
    environment = globals;
}

void Interpreter::interpret(std::list<Statement *> statements) {
    /*try {
        for (Stmt statement : statements) {
            execute(statement);
        }
    } catch (RuntimeError error) {
        Lox.runtimeError(error);
    }

*/
    try {
        for (Statement *statement: statements) {
            statement->execute(environment);
        }
    }
    catch (RuntimeException e) {
        std::cout << e.what();
    }
}
