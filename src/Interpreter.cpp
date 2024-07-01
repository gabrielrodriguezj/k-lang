#include "Interpreter.h"
#include "Exceptions/RuntimeException.h"
#include "Exceptions//NotImplementedYetException.h"
#include "Interpret/KFunction.h"
#include "Interpret/Return.h"

#include "Interpret/Statement/StmtBlock.h"
#include "Interpret/Statement/StmtExpression.h"
#include "Interpret/Statement/StmtIf.h"
#include "Interpret/Statement/StmtPrint.h"
#include "Interpret/Statement/StmtReturn.h"
#include "Interpret/Statement/StmtVariable.h"
#include "Interpret/Statement/StmtLoop.h"

Interpreter::Interpreter() {
    globals = new Environment();
    environment = globals;
}

void Interpreter::interpret(std::vector<Statement *> statements) {
    try {
        for (Statement *statement: statements) {
            execute(statement);
        }
    }
    catch (RuntimeException e) {
        std::cout << e.what();
    }
}

TData Interpreter::evaluate(Expression *expr){
    expr->accept(this);
}

void Interpreter::execute(Statement *statement){
    statement->accept(this);
}

TData Interpreter::visitAssignExpr(ExprAssignment *expr) {

}

TData Interpreter::visitArithmeticExpr(ExprArithmetic *expr) {

}

TData Interpreter::visitCallExpr(ExprCallFunction *expr) {

}

TData Interpreter::visitGetExpr(ExprGet *expr) {

}

TData Interpreter::visitGroupingExpr(ExprGrouping *expr) {

}

TData Interpreter::visitLiteralExpr(ExprLiteral *expr) {

}

TData Interpreter::visitLogicalExpr(ExprLogical *expr) {

}

TData Interpreter::visitRelational(ExprRelational *expr) {

}

TData Interpreter::visitSetExpr(ExprSet *expr) {

}

TData Interpreter::visitSuperExpr(ExprSuper *expr) {

}

TData Interpreter::visitThisExpr(ExprThis *expr) {

}

TData Interpreter::visitUnaryExpr(ExprUnary *expr) {

}

TData Interpreter::visitVariableExpr(ExprVariable *expr) {

}

void Interpreter::visitBlockStmt(StmtBlock *stmt) {
    Environment *blockEnvironment = new Environment();
    Environment *previous = this->environment;
    {
        this->environment = blockEnvironment;

        for(Statement *statement : stmt->getStatements()){
            execute(statement);
        }
    }

    this->environment = previous;

}

void Interpreter::visitClassStmt(StmtClass *stmt) {
    throw NotImplementedYetException("Not implemented yet");
}

void Interpreter::visitExpressionStmt(StmtExpression *stmt) {
    evaluate(stmt->getExpression());
}

void Interpreter::visitFunctionStmt(StmtFunction *stmt) {
    KFunction *function = new KFunction(stmt, environment, false);
    TData dataFunction = TData(function);
    environment->define(stmt->getName(), dataFunction);
}

void Interpreter::visitIfStmt(StmtIf *stmt) {
    TData solCondition = evaluate(stmt->getCondition());

    if (!std::holds_alternative<bool>(solCondition.getValue())) {
        throw RuntimeException("La condicion no es una expresion valida");
    }

    bool resCondition = std::get<bool>(solCondition.getValue());
    if(resCondition){
        execute(stmt->getThenBranch());
    }
    if(stmt->getElseBranch() != nullptr){
        execute(stmt->getElseBranch());
    }

}

void Interpreter::visitLoopStmt(StmtLoop *stmt) {
    TData solCondition = evaluate(stmt->getCondition());

    if (!std::holds_alternative<bool>(solCondition.getValue())) {
        throw RuntimeException("La condicion no es una expresion valida");
    }

    bool resCondition = std::get<bool>(solCondition.getValue());
    while (resCondition){
        execute(stmt->getBody());

        // Evaluate the condition after execute the body
        //solCondition = evaluate(stmt->getCondition());
        TData solCondition = TData(true);
        if (!std::holds_alternative<bool>(solCondition.getValue())) {
            throw RuntimeException("La condicion no es una expresion valida");
        }
        resCondition = std::get<bool>(solCondition.getValue());
    }
}

void Interpreter::visitPrintStmt(StmtPrint *stmt) {

    TData data = evaluate(stmt->getExpression());
    auto value = data.getValue();

    if(std::holds_alternative<std::monostate>(value)){
        std::cout<<"null"<<std::endl;
    }
    else if (std::holds_alternative<int>(value)) {
        std::cout<<std::get<int>(value)<<std::endl;
    }
    else if (std::holds_alternative<double>(value)) {
        std::cout<<std::get<double>(value)<<std::endl;
    }
    else if (std::holds_alternative<bool>(value)) {
        bool boolValue = std::get<bool>(value);
        std::cout<< (boolValue == 0 ? "false" : "true") <<std::endl;
    }
    else if (std::holds_alternative<std::string>(value)) {
        std::cout<<std::get<std::string>(value)<<std::endl;
    }
    else if (std::holds_alternative<KCallable*>(value)) {
        KCallable *callable = std::get<KCallable*>(value) ;
        if(dynamic_cast<KFunction*>(callable)){
            KFunction *function = dynamic_cast<KFunction*>(callable);
            std::cout<<function->toString()<<std::endl;
        }
    }
}

void Interpreter::visitReturnStmt(StmtReturn *stmt) {
    TData valueReturn;
    if(stmt->getValue() != nullptr){
        valueReturn = evaluate(stmt->getValue());
    }

    throw Return("Return", valueReturn);
}

void Interpreter::visitVarStmt(StmtVariable *stmt) {
    TData value;

    if(stmt->getInitializer() != nullptr){
        value = evaluate(stmt->getInitializer());
    }

    environment->define(stmt->getName(), value);
}


