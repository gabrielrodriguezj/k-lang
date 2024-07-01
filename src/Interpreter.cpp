#include <sstream>
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
#include "Interpret/Expression/ExprAssignment.h"
#include "Interpret/Expression/ExprArithmetic.h"
#include "Interpret/Expression/ExprCallFunction.h"
#include "Interpret/Expression/ExprGrouping.h"
#include "Interpret/Expression/ExprLiteral.h"
#include "Interpret/Expression/ExprLogical.h"
#include "Interpret/Expression/ExprRelational.h"
#include "Interpret/Expression/ExprUnary.h"
#include "Interpret/Expression/ExprVariable.h"

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
    TData value = evaluate(expr->getExpression());
    this->environment->assign(expr->getName(), value);
    return TData();
}

TData Interpreter::visitArithmeticExpr(ExprArithmetic *expr) {

    TData valueLeft = evaluate(expr->getLeft());
    TData valueRight = evaluate(expr->getRight());

    if(expr->getOper()->getName() == TokenName::PLUS){
        return valueLeft + valueRight;
    }
    if(expr->getOper()->getName() == TokenName::MINUS){
        return valueLeft - valueRight;
    }
    if(expr->getOper()->getName() == TokenName::STAR){
        return valueLeft * valueRight;
    }
    if(expr->getOper()->getName() == TokenName::SLASH){
        return valueLeft / valueRight;
    }

    return TData();
}

TData Interpreter::visitCallExpr(ExprCallFunction *expr) {
    TData calleeResult = evaluate(expr->getCallee());

    std::vector<TData> args;
    for (Expression *argument: expr->getArguments()) {
        TData result = evaluate(argument);
        args.push_back(result);
    }

    // Check if it's callable
    if (!std::holds_alternative<KCallable*>(calleeResult.getValue()) ) {
        throw RuntimeException("La expresion no corresponde a una llamada valida.");
    }
    KCallable *function = std::get<KCallable*>(calleeResult.getValue());

    // check arity
    if (expr->getArguments().size() != function->arity()) {
        std::stringstream ss;
        ss << "Se esperaron " << function->arity() << "argumentos pero se recibierion " << expr->getArguments().size();
        throw RuntimeException(ss.str());
    }

    return function->call(environment, args);
}

TData Interpreter::visitGetExpr(ExprGet *expr) {
    throw NotImplementedYetException("Not implemented yet");
}

TData Interpreter::visitGroupingExpr(ExprGrouping *expr) {
    return evaluate(expr->getExpression());
}

TData Interpreter::visitLiteralExpr(ExprLiteral *expr) {
    if (std::holds_alternative<int>(expr->getValue()) ) {
        int litVale = std::get<int>(expr->getValue());
        return TData(litVale);
    }

    if (std::holds_alternative<double>(expr->getValue()) ) {
        double litVale = std::get<double>(expr->getValue());
        return TData(litVale);
    }

    if (std::holds_alternative<bool>(expr->getValue()) ) {
        bool litVale = std::get<bool>(expr->getValue());
        return TData(litVale);
    }

    if (std::holds_alternative<std::string>(expr->getValue()) ) {
        std::string litVale = std::get<std::string>(expr->getValue());
        return TData(litVale);
    }

    return TData();
}

TData Interpreter::visitLogicalExpr(ExprLogical *expr) {
    TData valueLeft = evaluate(expr->getLeft());
    TData valueRight = evaluate(expr->getRight());

    if(expr->getOper()->getName() == TokenName::OR){
        return valueLeft || valueRight;
    }

    if(expr->getOper()->getName() == TokenName::AND){
        return valueLeft && valueRight;
    }

    return TData();
}

TData Interpreter::visitRelational(ExprRelational *expr) {
    TData valueLeft = evaluate(expr->getLeft());
    TData valueRight = evaluate(expr->getRight());

    if(expr->getOper()->getName() == TokenName::LESS){
        return valueLeft < valueRight;
    }
    if(expr->getOper()->getName() == TokenName::LESS_EQUAL){
        return valueLeft <= valueRight;
    }
    if(expr->getOper()->getName() == TokenName::GREATER){
        return valueLeft > valueRight;
    }
    if(expr->getOper()->getName() == TokenName::GREATER_EQUAL){
        return valueLeft >= valueRight;
    }
    if(expr->getOper()->getName() == TokenName::BANG_EQUAL){
        return valueLeft != valueRight;
    }
    if(expr->getOper()->getName() == TokenName::EQUAL_EQUAL){
        return valueLeft == valueRight;
    }

    return TData();
}

TData Interpreter::visitSetExpr(ExprSet *expr) {
    throw NotImplementedYetException("Not implemented yet");
}

TData Interpreter::visitSuperExpr(ExprSuper *expr) {
    throw NotImplementedYetException("Not implemented yet");
}

TData Interpreter::visitThisExpr(ExprThis *expr) {
    throw NotImplementedYetException("Not implemented yet");
}

TData Interpreter::visitUnaryExpr(ExprUnary *expr) {
    TData valueLeft = evaluate(expr->getLeft());

    if(expr->getOper()->getName() == TokenName::MINUS){
        return -valueLeft;
    }
    if(expr->getOper()->getName() == TokenName::BANG){
        return !valueLeft;
    }

    return TData();
}

TData Interpreter::visitVariableExpr(ExprVariable *expr) {
    return this->environment->get(expr->getName());
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


