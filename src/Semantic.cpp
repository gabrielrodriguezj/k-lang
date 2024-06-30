#include "Semantic.h"

Semantic::Semantic(const std::vector<Statement *> &statements) : statements(statements) {}

void Semantic::analyse() {
    for(const Statement* statement : statements){
        //resolve(statement);
    }
}








