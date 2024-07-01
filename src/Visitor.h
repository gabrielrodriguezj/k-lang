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
class KData;

class Visitor {
public:
    virtual KData visitAssignExpr(ExprAssignment *expr) = 0;
    virtual KData visitArithmeticExpr(ExprArithmetic *expr) = 0;
    virtual KData visitCallExpr(ExprCallFunction *expr) = 0;
    virtual KData visitGetExpr(ExprGet *expr) = 0;
    virtual KData visitGroupingExpr(ExprGrouping *expr) = 0;
    virtual KData visitLiteralExpr(ExprLiteral *expr) = 0;
    virtual KData visitLogicalExpr(ExprLogical *expr) = 0;
    virtual KData visitRelational(ExprRelational *expr) = 0;
    virtual KData visitSetExpr(ExprSet *expr) = 0;
    virtual KData visitSuperExpr(ExprSuper *expr) = 0;
    virtual KData visitThisExpr(ExprThis *expr) = 0;
    virtual KData visitUnaryExpr(ExprUnary *expr) = 0;
    virtual KData visitVariableExpr(ExprVariable *expr) = 0;

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
