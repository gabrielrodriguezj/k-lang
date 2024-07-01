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
    TData evaluate(Expression *expr);

    void execute(Statement *stmt);

    TData visitAssignExpr(ExprAssignment *expr) override;

    TData visitArithmeticExpr(ExprArithmetic *expr) override;

    TData visitCallExpr(ExprCallFunction *expr) override;

    TData visitGetExpr(ExprGet *expr) override;

    TData visitGroupingExpr(ExprGrouping *expr) override;

    TData visitLiteralExpr(ExprLiteral *expr) override;

    TData visitLogicalExpr(ExprLogical *expr) override;

    TData visitRelational(ExprRelational *expr) override;

    TData visitSetExpr(ExprSet *expr) override;

    TData visitSuperExpr(ExprSuper *expr) override;

    TData visitThisExpr(ExprThis *expr) override;

    TData visitUnaryExpr(ExprUnary *expr) override;

    TData visitVariableExpr(ExprVariable *expr) override;

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
