#ifndef K_LANG_VISITOREXPRESSION_H
#define K_LANG_VISITOREXPRESSION_H

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
class KData;

class VisitorExpression {
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

};


#endif //K_LANG_VISITOREXPRESSION_H
