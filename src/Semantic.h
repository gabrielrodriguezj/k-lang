#ifndef K_LANG_SEMANTIC_H
#define K_LANG_SEMANTIC_H

#include "Core/Expression/Expression.h"
#include "Core/Statement/Statement.h"

class Semantic: public VisitorExpression, VisitorStatement{
public:
    explicit Semantic(const std::vector<Statement *> &statements);
    void analyse();
private:
    std::vector<Statement*> statements;
    void resolve(std::vector<Statement *>);
    void resolve(Statement*);
    void resolve(Expression*);

    void visitBlockStmt(StmtBlock *stmt) override;

    void visitClassStmt(StmtClass *stmt) override;

    void visitExpressionStmt(StmtExpression *stmt) override;

    void visitFunctionStmt(StmtFunction *stmt) override;

    void visitIfStmt(StmtIf *stmt) override;

    void visitLoopStmt(StmtLoop *stmt) override;

    void visitPrintStmt(StmtPrint *stmt) override;

    void visitReturnStmt(StmtReturn *stmt) override;

    void visitVarStmt(StmtVariable *stmt) override;
};


#endif //K_LANG_SEMANTIC_H
