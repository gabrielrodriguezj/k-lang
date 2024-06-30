#include "StmtBlock.h"

StmtBlock::StmtBlock(const std::vector<Statement *> &statements) : statements(statements) {}

void StmtBlock::accept(Visitor *visitor) {
    visitor->visitBlockStmt(this);
}
