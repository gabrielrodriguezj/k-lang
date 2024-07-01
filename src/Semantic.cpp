#include "Semantic.h"

#include "Core/Statement/StmtBlock.h"
#include "Core/Statement/StmtExpression.h"
#include "Core/Statement/StmtFunction.h"
#include "Core/Statement/StmtIf.h"
#include "Core/Statement/StmtPrint.h"
#include "Core/Statement/StmtReturn.h"
#include "Core/Statement/StmtVariable.h"
#include "Core/Statement/StmtLoop.h"
#include "Core/Expression/ExprAssignment.h"
#include "Core/Expression/ExprArithmetic.h"
#include "Core/Expression/ExprCallFunction.h"
#include "Core/Expression/ExprGrouping.h"
#include "Core/Expression/ExprLiteral.h"
#include "Core/Expression/ExprLogical.h"
#include "Core/Expression/ExprRelational.h"
#include "Core/Expression/ExprUnary.h"
#include "Core/Expression/ExprVariable.h"
#include "Exceptions/NotImplementedYetException.h"

Semantic::Semantic(const std::vector<Statement *> &statements) : statements(statements) {}

void Semantic::analyse() {
    resolve(statements);
}

void Semantic::resolve(std::vector<Statement *> statements){
    for(Statement* statement : statements){
        resolve(statement);
    }
}

void Semantic::resolve(Statement *stmt) {
    stmt->accept(this);
}

void Semantic::resolve(Expression *expr) {
    expr->accept(this);
}

void Semantic::visitBlockStmt(StmtBlock *stmt) {
    //beginScope();
    resolve(stmt->getStatements());
    //endScope();
}

void Semantic::visitClassStmt(StmtClass *stmt) {
    throw NotImplementedYetException("Not implemented yet");
}

void Semantic::visitExpressionStmt(StmtExpression *stmt) {
    resolve(stmt->getExpression());
}

void Semantic::visitFunctionStmt(StmtFunction *stmt) {
    //declare(stmt->getName());
    //define(stmt->getName());

    //resolveFunction(stmt, FunctionType.FUNCTION);
}

void Semantic::visitIfStmt(StmtIf *stmt) {
    resolve(stmt->getCondition());
    resolve(stmt->getThenBranch());
    if (stmt->getElseBranch() != nullptr) resolve(stmt->getElseBranch());
}

void Semantic::visitLoopStmt(StmtLoop *stmt) {

}

void Semantic::visitPrintStmt(StmtPrint *stmt) {
    resolve(stmt->getExpression());
}

void Semantic::visitReturnStmt(StmtReturn *stmt) {

}

void Semantic::visitVarStmt(StmtVariable *stmt) {

}








