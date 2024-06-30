#ifndef K_LANG_VISITOR_H
#define K_LANG_VISITOR_H


#include "Interpret/Expression/ExprAssignment.h"
#include "Interpret/Expression/ExprArithmetic.h"
#include "Interpret/Expression/ExprLogical.h"
#include "Interpret/Expression/ExprRelational.h"
#include "Interpret/Expression/ExprCallFunction.h"
#include "Interpret/Expression/ExprGet.h"
#include "Interpret/Expression/ExprGrouping.h"
#include "Interpret/Expression/ExprLiteral.h"
#include "Interpret/Expression/ExprSet.h"
#include "Interpret/Expression/ExprSuper.h"
#include "Interpret/Expression/ExprThis.h"
#include "Interpret/Expression/ExprUnary.h"
#include "Interpret/Expression/ExprVariable.h"
#include "Interpret/Statement/StmtBlock.h"
#include "Interpret/Statement/StmtClass.h"
#include "Interpret/Statement/StmtExpression.h"
#include "Interpret/Statement/StmtIf.h"
#include "Interpret/Statement/StmtPrint.h"
#include "Interpret/Statement/StmtReturn.h"
#include "Interpret/Statement/StmtLoop.h"

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
    virtual void visitVarStmt(StmtVariable *stmt) const = 0;

};


#endif //K_LANG_VISITOR_H
