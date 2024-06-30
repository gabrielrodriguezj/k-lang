#include "Semantic.h"

Semantic::Semantic(const std::vector<Statement *> &statements) : statements(statements) {}

void Semantic::analyse() {
    for(const Statement* statement : statements){
        //resolve(statement);
    }
}

void resolve(Statement *statement) {
    //stmt.accept(this);
}

void Semantic::resolve(const std::vector<Statement *> &statements) {
    for(const Statement* statement : statements){
        //resolve(statement);
    }
}

void visitBlockStmt(StmtBlock stmt) {
    //beginScope();
    //resolve(stmt.statements);
    //endScope();
    //return null;
}






