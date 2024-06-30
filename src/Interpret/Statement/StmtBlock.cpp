#include "StmtBlock.h"
#include "../../Exceptions/NotImplementedYetException.h"

StmtBlock::StmtBlock(const std::vector<Statement *> &statements) : statements(statements) {}

void StmtBlock::execute(Environment* environment) {
    // Local environment for local variables
    Environment* local = new Environment(environment);

    for(Statement *statement : statements){
        statement->execute(local);
    }
}

void StmtBlock::accept(Visitor *visitor) const {
    visitor->visitBlockStmt(this);
}
