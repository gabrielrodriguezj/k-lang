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
#include "Exceptions/SemanticException.h"


Semantic::Semantic(Interpreter *interpreter) : interpreter(interpreter) {}

void Semantic::analyse(std::vector<Statement *> statements) {
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

void Semantic::beginScope() {
    std::map<std::string, bool> newStack;
    scopes.push_back(newStack);
}

void Semantic::endScope() {
    scopes.pop_back();
}

void Semantic::declare(IdToken *name) {
    if (scopes.empty() == 0) return;

    //std::map<std::string, bool>
    auto scope = scopes.back();
    if (scope.contains(name->getIdentifier())) {
        throw SemanticException("Ya existe una variable con este nombre en el mismo alcance");
    }

    scope[name->getIdentifier()] = false;
}

void Semantic::define(IdToken *name) {
    if (scopes.empty()) return;
    scopes.back()[name->getIdentifier()] = true;
}

void Semantic::resolveLocal(Expression *expr, IdToken *name) {
    for (int i = scopes.size() - 1; i >= 0; i--) {
        if (scopes[i].contains(name->getIdentifier())) {
            interpreter->resolve(expr, scopes.size() - 1 - i);
            return;
        }
    }
}

void Semantic::resolveFunction(StmtFunction *function) {
    beginScope();
    for (IdToken* param : function->getParams()) {
        declare(param);
        define(param);
    }
    resolve(function->getBody());
    endScope();
}

void Semantic::visitBlockStmt(StmtBlock *stmt) {
    beginScope();
    resolve(stmt->getStatements());
    endScope();
}

void Semantic::visitClassStmt(StmtClass *stmt) {
    throw NotImplementedYetException("Not implemented yet");
}

void Semantic::visitExpressionStmt(StmtExpression *stmt) {
    resolve(stmt->getExpression());
}

void Semantic::visitFunctionStmt(StmtFunction *stmt) {
    declare(stmt->getName());
    define(stmt->getName());
    /*
     * Se define el nombre de la función, antes de resolver su cuerpo. Esto
     * permite que una función se refiera recursivamente a sí misma dentro
     * de su propio cuerpo.
     */

    resolveFunction(stmt);
}

void Semantic::visitIfStmt(StmtIf *stmt) {
    resolve(stmt->getCondition());
    resolve(stmt->getThenBranch());
    if (stmt->getElseBranch() != nullptr) resolve(stmt->getElseBranch());
}

void Semantic::visitLoopStmt(StmtLoop *stmt) {
    resolve(stmt->getCondition());
    resolve(stmt->getBody());
}

void Semantic::visitPrintStmt(StmtPrint *stmt) {
    resolve(stmt->getExpression());
}

void Semantic::visitReturnStmt(StmtReturn *stmt) {
    if (stmt->getValue() != nullptr) {
        resolve(stmt->getValue());
    }
}

void Semantic::visitVarStmt(StmtVariable *stmt) {
    declare(stmt->getName());
    if (stmt->getInitializer() != nullptr) {
        resolve(stmt->getInitializer());
    }
    define(stmt->getName());
}

KData Semantic::visitAssignExpr(ExprAssignment *expr) {
    resolve(expr->getExpression());
    resolveLocal(expr, expr->getName());
    return KData();
}

KData Semantic::visitArithmeticExpr(ExprArithmetic *expr) {
    resolve(expr->getLeft());
    resolve(expr->getRight());
    return KData();
}

KData Semantic::visitCallExpr(ExprCallFunction *expr) {
    resolve(expr->getCallee());

    for (Expression *argument : expr->getArguments()) {
        resolve(argument);
    }
    return KData();
}

KData Semantic::visitGetExpr(ExprGet *expr) {
    return KData();
}

KData Semantic::visitGroupingExpr(ExprGrouping *expr) {
    resolve(expr->getExpression());
    return KData();
}

KData Semantic::visitLiteralExpr(ExprLiteral *expr) {
    // Do nothing
    return KData();
}

KData Semantic::visitLogicalExpr(ExprLogical *expr) {
    resolve(expr->getLeft());
    resolve(expr->getRight());
    return KData();
}

KData Semantic::visitRelational(ExprRelational *expr) {
    resolve(expr->getLeft());
    resolve(expr->getRight());
    return KData();
}

KData Semantic::visitSetExpr(ExprSet *expr) {
    return KData();
}

KData Semantic::visitSuperExpr(ExprSuper *expr) {
    return KData();
}

KData Semantic::visitThisExpr(ExprThis *expr) {
    return KData();
}

KData Semantic::visitUnaryExpr(ExprUnary *expr) {
    resolve(expr->getLeft());
    return KData();
}

KData Semantic::visitVariableExpr(ExprVariable *expr) {
    if (!scopes.empty() &&
        scopes.back()[expr->getName()->getIdentifier()] == false) {

        throw SemanticException("No se puede leer la variable local porque no se ha incializado.");
    }

    resolveLocal(expr, expr->getName());
    return KData();
}

