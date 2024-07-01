#ifndef K_LANG_INTERPRETER_H
#define K_LANG_INTERPRETER_H

#include "Environment.h"
#include "Core/Expression/Expression.h"
#include "Core/Statement/Statement.h"
#include <vector>

class Interpreter : public VisitorExpression, VisitorStatement{
private:
    Environment* globals;
    Environment* environment;
    std::map<Expression*, int> locals;
public:
    Interpreter();
    void interpret(std::vector<Statement*> statements);

private:
    KData evaluate(Expression *expr);

    void execute(Statement *stmt);

    KData visitAssignExpr(ExprAssignment *expr) override;

    KData visitArithmeticExpr(ExprArithmetic *expr) override;

    KData visitCallExpr(ExprCallFunction *expr) override;

    KData visitGetExpr(ExprGet *expr) override;

    KData visitGroupingExpr(ExprGrouping *expr) override;

    KData visitLiteralExpr(ExprLiteral *expr) override;

    KData visitLogicalExpr(ExprLogical *expr) override;

    KData visitRelational(ExprRelational *expr) override;

    KData visitSetExpr(ExprSet *expr) override;

    KData visitSuperExpr(ExprSuper *expr) override;

    KData visitThisExpr(ExprThis *expr) override;

    KData visitUnaryExpr(ExprUnary *expr) override;

    KData visitVariableExpr(ExprVariable *expr) override;

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
