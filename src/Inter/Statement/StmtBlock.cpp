#include "StmtBlock.h"
#include "../../Exceptions/NotImplementedYetException.h"

StmtBlock::StmtBlock(const std::list<Statement *> &statements) : statements(statements) {}

void StmtBlock::execute(Environment* environment) {
    // Local environment for local variables
    Environment* local = new Environment(environment);

    for(Statement *statement : statements){
        statement->execute(local);
    }
}
