#include "StmtBlock.h"

StmtBlock::StmtBlock(const std::vector<Statement *> &statements) : statements(statements) {}

void StmtBlock::accept(Visitor *visitor) {
    visitor->visitBlockStmt(this);
}

std::vector<Statement *> StmtBlock::getStatements() {
    return statements;
}
