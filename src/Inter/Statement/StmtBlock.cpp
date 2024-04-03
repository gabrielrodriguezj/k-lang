#include "StmtBlock.h"
#include "../../Exceptions/NotImplementedYetException.h"

StmtBlock::StmtBlock(const std::list<Statement *> &statements) : statements(statements) {}

void StmtBlock::execute(Environment* environment) {
    throw NotImplementedYetException("Not implemented yet");
}
