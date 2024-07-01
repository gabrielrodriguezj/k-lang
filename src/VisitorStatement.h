#ifndef K_LANG_VISITORSTATEMENT_H
#define K_LANG_VISITORSTATEMENT_H

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

class VisitorStatement {
public:
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


#endif //K_LANG_VISITORSTATEMENT_H
