#ifndef K_LANG_SEMANTIC_H
#define K_LANG_SEMANTIC_H

#include "Interpreter.h"

class Semantic: public VisitorExpression, VisitorStatement{
public:
    explicit Semantic(Interpreter *);

    void analyse(std::vector<Statement *>);
private:
    Interpreter *interpreter;
    //std::vector<Statement*> statements;
    /*
     * scopes en realidad debería ser un stack pero por el uso
     * que se le dará en algunos métodos, es más conveniente
     * usarlo como vector
     */
    std::vector< std::map<std::string, bool> > scopes;

    void resolve(std::vector<Statement *>);
    void resolve(Statement*);
    void resolve(Expression*);
    void beginScope();
    void endScope();
    void declare(IdToken*);
    void define(IdToken*);
    void resolveLocal(Expression*, IdToken*);
    void resolveFunction(StmtFunction*);

    void visitBlockStmt(StmtBlock *stmt) override;

    void visitClassStmt(StmtClass *stmt) override;

    void visitExpressionStmt(StmtExpression *stmt) override;

    void visitFunctionStmt(StmtFunction *stmt) override;

    void visitIfStmt(StmtIf *stmt) override;

    void visitLoopStmt(StmtLoop *stmt) override;

    void visitPrintStmt(StmtPrint *stmt) override;

    void visitReturnStmt(StmtReturn *stmt) override;

    void visitVarStmt(StmtVariable *stmt) override;

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
};


#endif //K_LANG_SEMANTIC_H
