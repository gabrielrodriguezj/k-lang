#ifndef K_LANG_INTERPRETER_H
#define K_LANG_INTERPRETER_H


#include <vector>
#include "Environment.h"
#include "Expression/Expression.h"
#include "Statement/Statement.h"

class Visitor;

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
