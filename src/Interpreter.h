#ifndef K_LANG_INTERPRETER_H
#define K_LANG_INTERPRETER_H

#include "Environment.h"
#include <vector>

class Expression;
class Statement;
class Environment;

class Interpreter {
private:
    Environment* globals;
    Environment* environment;
    std::map<Expression*, int> locals;

public:
    Interpreter();
    void interpret(std::vector<Statement*> statements);
};


#endif //K_LANG_INTERPRETER_H
