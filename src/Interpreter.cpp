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

void Interpreter::evaluate(Expression *expr){
    expr->accept(this);
}

void Interpreter::execute(Statement *statement){
    statement->accept(this);
}

void Interpreter::visitAssignExpr(ExprAssignment *expr) {

}

void Interpreter::visitArithmeticExpr(ExprArithmetic *expr) {

}

void Interpreter::visitCallExpr(ExprCallFunction *expr) {

}

void Interpreter::visitGetExpr(ExprGet *expr) {

}

void Interpreter::visitGroupingExpr(ExprGrouping *expr) {

}

void Interpreter::visitLiteralExpr(ExprLiteral *expr) {

}

void Interpreter::visitLogicalExpr(ExprLogical *expr) {

}

void Interpreter::visitRelational(ExprRelational *expr) {

}

void Interpreter::visitSetExpr(ExprSet *expr) {

}

void Interpreter::visitSuperExpr(ExprSuper *expr) {

}

void Interpreter::visitThisExpr(ExprThis *expr) {

}

void Interpreter::visitUnaryExpr(ExprUnary *expr) {

}

void Interpreter::visitVariableExpr(ExprVariable *expr) {

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
    //TData solCondition = evaluate(stmt->getCondition());
    TData solCondition = TData(true);

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
    //TData solCondition = evaluate(stmt->getCondition());
    TData solCondition = TData(true);

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

    //TData data = evaluate(stmt->getExpression());
    TData data = TData(true);
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
        //valueReturn = evaluate(stmt->getValue());
        valueReturn = TData(true);
    }

    throw Return("Return", valueReturn);
}

void Interpreter::visitVarStmt(StmtVariable *stmt) {
    TData value;

    if(stmt->getInitializer() != nullptr){
        //value = evaluate(stmt->getInitializer());
        value = TData(true);
    }

    environment->define(stmt->getName(), value);
}


