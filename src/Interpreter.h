#ifndef K_LANG_INTERPRETER_H
#define K_LANG_INTERPRETER_H

#include "Environment.h"
#include "Visitor.h"
#include "Interpret/Expression/Expression.h"
#include "Interpret/Statement/Statement.h"
#include <vector>

class Interpreter : public Visitor{
private:
    Environment* globals;
    Environment* environment;
    std::map<Expression*, int> locals;
public:
    Interpreter();
    void interpret(std::vector<Statement*> statements);

private:
    void evaluate(Expression *expr);

    void execute(Statement *stmt);

    void visitAssignExpr(ExprAssignment *expr) override;

    void visitArithmeticExpr(ExprArithmetic *expr) override;

    void visitCallExpr(ExprCallFunction *expr) override;

    void visitGetExpr(ExprGet *expr) override;

    void visitGroupingExpr(ExprGrouping *expr) override;

    void visitLiteralExpr(ExprLiteral *expr) override;

    void visitLogicalExpr(ExprLogical *expr) override;

    void visitRelational(ExprRelational *expr) override;

    void visitSetExpr(ExprSet *expr) override;

    void visitSuperExpr(ExprSuper *expr) override;

    void visitThisExpr(ExprThis *expr) override;

    void visitUnaryExpr(ExprUnary *expr) override;

    void visitVariableExpr(ExprVariable *expr) override;

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


#endif //K_LANG_INTERPRETER_H
