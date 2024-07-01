#include <sstream>
#include "Interpreter.h"
#include "Exceptions/RuntimeException.h"
#include "Exceptions//NotImplementedYetException.h"
#include "Core/KFunction.h"
#include "Core/Return.h"

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

KData Interpreter::evaluate(Expression *expr){
    return expr->accept(this);
}

void Interpreter::execute(Statement *statement){
    statement->accept(this);
}

KData Interpreter::visitAssignExpr(ExprAssignment *expr) {
    KData value = evaluate(expr->getExpression());
    this->environment->assign(expr->getName(), value);
    return KData();
}

KData Interpreter::visitArithmeticExpr(ExprArithmetic *expr) {

    KData valueLeft = evaluate(expr->getLeft());
    KData valueRight = evaluate(expr->getRight());

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

    return KData();
}

KData Interpreter::visitCallExpr(ExprCallFunction *expr) {
    KData calleeResult = evaluate(expr->getCallee());

    std::vector<KData> args;
    for (Expression *argument: expr->getArguments()) {
        KData result = evaluate(argument);
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

KData Interpreter::visitGetExpr(ExprGet *expr) {
    throw NotImplementedYetException("Not implemented yet");
}

KData Interpreter::visitGroupingExpr(ExprGrouping *expr) {
    return evaluate(expr->getExpression());
}

KData Interpreter::visitLiteralExpr(ExprLiteral *expr) {
    if (std::holds_alternative<int>(expr->getValue()) ) {
        int litVale = std::get<int>(expr->getValue());
        return KData(litVale);
    }

    if (std::holds_alternative<double>(expr->getValue()) ) {
        double litVale = std::get<double>(expr->getValue());
        return KData(litVale);
    }

    if (std::holds_alternative<bool>(expr->getValue()) ) {
        bool litVale = std::get<bool>(expr->getValue());
        return KData(litVale);
    }

    if (std::holds_alternative<std::string>(expr->getValue()) ) {
        std::string litVale = std::get<std::string>(expr->getValue());
        return KData(litVale);
    }

    return KData();
}

KData Interpreter::visitLogicalExpr(ExprLogical *expr) {
    KData valueLeft = evaluate(expr->getLeft());
    KData valueRight = evaluate(expr->getRight());

    if(expr->getOper()->getName() == TokenName::OR){
        return valueLeft || valueRight;
    }

    if(expr->getOper()->getName() == TokenName::AND){
        return valueLeft && valueRight;
    }

    return KData();
}

KData Interpreter::visitRelational(ExprRelational *expr) {
    KData valueLeft = evaluate(expr->getLeft());
    KData valueRight = evaluate(expr->getRight());

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

    return KData();
}

KData Interpreter::visitSetExpr(ExprSet *expr) {
    throw NotImplementedYetException("Not implemented yet");
}

KData Interpreter::visitSuperExpr(ExprSuper *expr) {
    throw NotImplementedYetException("Not implemented yet");
}

KData Interpreter::visitThisExpr(ExprThis *expr) {
    throw NotImplementedYetException("Not implemented yet");
}

KData Interpreter::visitUnaryExpr(ExprUnary *expr) {
    KData valueLeft = evaluate(expr->getLeft());

    if(expr->getOper()->getName() == TokenName::MINUS){
        return -valueLeft;
    }
    if(expr->getOper()->getName() == TokenName::BANG){
        return !valueLeft;
    }

    return KData();
}

KData Interpreter::visitVariableExpr(ExprVariable *expr) {
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
    KData dataFunction = KData(function);
    environment->define(stmt->getName(), dataFunction);
}

void Interpreter::visitIfStmt(StmtIf *stmt) {
    KData solCondition = evaluate(stmt->getCondition());

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
    KData solCondition = evaluate(stmt->getCondition());

    if (!std::holds_alternative<bool>(solCondition.getValue())) {
        throw RuntimeException("La condicion no es una expresion valida");
    }

    bool resCondition = std::get<bool>(solCondition.getValue());
    while (resCondition){
        execute(stmt->getBody());

        // Evaluate the condition after execute the body
        //solCondition = evaluate(stmt->getCondition());
        KData solCondition = KData(true);
        if (!std::holds_alternative<bool>(solCondition.getValue())) {
            throw RuntimeException("La condicion no es una expresion valida");
        }
        resCondition = std::get<bool>(solCondition.getValue());
    }
}

void Interpreter::visitPrintStmt(StmtPrint *stmt) {

    KData data = evaluate(stmt->getExpression());
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
    KData valueReturn;
    if(stmt->getValue() != nullptr){
        valueReturn = evaluate(stmt->getValue());
    }

    throw Return("Return", valueReturn);
}

void Interpreter::visitVarStmt(StmtVariable *stmt) {
    KData value;

    if(stmt->getInitializer() != nullptr){
        value = evaluate(stmt->getInitializer());
    }

    environment->define(stmt->getName(), value);
}


