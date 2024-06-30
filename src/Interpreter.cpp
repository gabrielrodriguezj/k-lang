#include "Interpreter.h"
#include "Exceptions/RuntimeException.h"

Interpreter::Interpreter() {
    globals = new Environment(nullptr);
    environment = globals;
}

void Interpreter::interpret(std::vector<Statement *> statements) {
    try {
        for (Statement *statement: statements) {
            //statement->execute(environment);
        }
    }
    catch (RuntimeException e) {
        std::cout << e.what();
    }
}
