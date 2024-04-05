#ifndef K_LANG_INTERPRETER_H
#define K_LANG_INTERPRETER_H


#include <list>
#include "Environment.h"
#include "Expression/Expression.h"
#include "Statement/Statement.h"

class Interpreter {
private:
    Environment* globals;
    Environment* environment;
    std::map<Expression*, int> locals;

public:
    Interpreter();
    void interpret(std::list<Statement*> statements);
};


#endif //K_LANG_INTERPRETER_H
