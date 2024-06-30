#ifndef K_LANG_VISITOR_H
#define K_LANG_VISITOR_H

class ExprAssignment;
class ExprArithmetic;
class ExprLogical;
class ExprRelational;
class ExprCallFunction;
class ExprGet;
class ExprGrouping;
class ExprLiteral;
class ExprSet;
class ExprSuper;
class ExprThis;
class ExprUnary;
class ExprVariable;
class StmtBlock;
class StmtClass;
class StmtExpression;
class StmtFunction;
class StmtIf;
class StmtPrint;
class StmtReturn;
class StmtLoop;

class Visitor {
public:
    virtual void visitAssignExpr(ExprAssignment *expr) const = 0;
    virtual void visitArithmeticExpr(ExprArithmetic *expr) const = 0;
    virtual void visitCallExpr(ExprCallFunction *expr) const = 0;
    virtual void visitGetExpr(ExprGet *expr) const = 0;
    virtual void visitGroupingExpr(ExprGrouping *expr) const = 0;
    virtual void visitLiteralExpr(ExprLiteral *expr) const = 0;
    virtual void visitLogicalExpr(ExprLogical *expr) const = 0;
    virtual void visitRelational(ExprRelational *expr) const = 0;
    virtual void visitSetExpr(ExprSet *expr) const = 0;
    virtual void visitSuperExpr(ExprSuper *expr) const = 0;
    virtual void visitThisExpr(ExprThis *expr) const = 0;
    virtual void visitUnaryExpr(ExprUnary *expr) const = 0;
    virtual void visitVariableExpr(ExprVariable *expr) const = 0;

    virtual void visitBlockStmt(StmtBlock *stmt) const = 0;
    virtual void visitClassStmt(StmtClass *stmt) const = 0;
    virtual void visitExpressionStmt(StmtExpression *stmt) const = 0;
    virtual void visitFunctionStmt(StmtFunction *stmt) const = 0;
    virtual void visitIfStmt(StmtIf *stmt) const = 0;
    virtual void visitLoopStmt(StmtLoop *stmt) const = 0;
    virtual void visitPrintStmt(StmtPrint *stmt) const = 0;
    virtual void visitReturnStmt(StmtReturn *stmt) const = 0;
    //virtual void visitVarStmt(StmtVariable *stmt) const = 0;

};


#endif //K_LANG_VISITOR_H
