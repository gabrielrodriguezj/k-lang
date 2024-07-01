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
class ExprVariable;
class ExprUnary;
class StmtBlock;
class StmtClass;
class StmtExpression;
class StmtFunction;
class StmtIf;
class StmtPrint;
class StmtReturn;
class StmtLoop;
class StmtVariable;
class TData;

class Visitor {
public:
    virtual TData visitAssignExpr(ExprAssignment *expr) = 0;
    virtual TData visitArithmeticExpr(ExprArithmetic *expr) = 0;
    virtual TData visitCallExpr(ExprCallFunction *expr) = 0;
    virtual TData visitGetExpr(ExprGet *expr) = 0;
    virtual TData visitGroupingExpr(ExprGrouping *expr) = 0;
    virtual TData visitLiteralExpr(ExprLiteral *expr) = 0;
    virtual TData visitLogicalExpr(ExprLogical *expr) = 0;
    virtual TData visitRelational(ExprRelational *expr) = 0;
    virtual TData visitSetExpr(ExprSet *expr) = 0;
    virtual TData visitSuperExpr(ExprSuper *expr) = 0;
    virtual TData visitThisExpr(ExprThis *expr) = 0;
    virtual TData visitUnaryExpr(ExprUnary *expr) = 0;
    virtual TData visitVariableExpr(ExprVariable *expr) = 0;

    virtual void visitBlockStmt(StmtBlock *stmt) = 0;
    virtual void visitClassStmt(StmtClass *stmt) = 0;
    virtual void visitExpressionStmt(StmtExpression *stmt) = 0;
    virtual void visitFunctionStmt(StmtFunction *stmt) = 0;
    virtual void visitIfStmt(StmtIf *stmt) = 0;
    virtual void visitLoopStmt(StmtLoop *stmt) = 0;
    virtual void visitPrintStmt(StmtPrint *stmt) = 0;
    virtual void visitReturnStmt(StmtReturn *stmt) = 0;
    virtual void visitVarStmt(StmtVariable *stmt) = 0;

};


#endif //K_LANG_VISITOR_H
