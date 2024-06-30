#include "StmtBlock.h"
#include "../../Exceptions/NotImplementedYetException.h"

StmtBlock::StmtBlock(const std::vector<Statement *> &statements) : statements(statements) {}

void StmtBlock::accept(Visitor *visitor) const {
    //visitor->visitBlockStmt(this);
}
