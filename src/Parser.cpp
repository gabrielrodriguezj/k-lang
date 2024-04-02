#include <sstream>
#include "Parser.h"
#include "Scanner.h"
#include "Token/TokenUtil.h"
#include "Exceptions/ParserException.h"
#include "Inter/ExprLiteral.h"
#include "Inter/ExprThis.h"
#include "Token/NumberToken.h"
#include "Token/StringToken.h"
#include "Inter/ExprVariable.h"
#include "Token/IdToken.h"
#include "Inter/ExprSuper.h"
#include "Inter/ExprGrouping.h"
#include "Inter/ExprCallFunction.h"
#include "Inter/ExprGet.h"
#include "Inter/ExprUnary.h"
#include "Inter/ExprArithmetic.h"
#include "Inter/ExprRelational.h"
#include "Inter/ExprLogical.h"
#include "Inter/ExprAssignment.h"
#include "Inter/ExprSet.h"
#include "Inter/Statement.h"
#include "Inter/StmtClass.h"

Parser::Parser(const std::string& source) {
    scanner = new Scanner(source);
}

bool Parser::parse() {
    preanalysis = scanner->next();
    while (true) {
        program();

        if (preanalysis->getName() != TokenName::END) {
            std::stringstream ss;
            ss<<"Error: Expresion no valida, no se esperaba el token '"<< tokennameToString(preanalysis->getName());
            ss<<"'. Linea: " << preanalysis->getLine();
            throw ParserException(ss.str());
        } else {
            return true;
        }
    }
}

void Parser::match(TokenName name) {
    if(preanalysis->getName() == name){
        previous = preanalysis;
        preanalysis = scanner->next();
    }
    else{
        std::stringstream ss;
        ss<<"Error: Se esperaba el token '"<< tokennameToString(name);
        ss<<"' pero se recibio el token '" << tokennameToString(preanalysis->getName());
        ss<<"'. Linea: " << preanalysis->getLine();
        throw ParserException(ss.str());
    }
}

// Declarations:

void Parser::program() {
    std::list<Statement*> statements;
    declaration(statements);
}

void Parser::declaration(std::list<Statement*> statements) {
    Statement* stmt;
    switch (preanalysis->getName()) {
        case TokenName::CLASS:
            stmt = classDeclaration();
            statements.push_back(stmt);
            declaration(statements);
            break;
        case TokenName::FUN:
            stmt = functionDeclaration();
            statements.push_back(stmt);
            declaration(statements);
            break;
        case TokenName::VAR:
            stmt = variableDeclaration();
            statements.push_back(stmt);
            declaration(statements);
            break;
        case TokenName::FOR:
        case TokenName::IF:
        case TokenName::WHILE:
        case TokenName::PRINT:
        case TokenName::RETURN:
        case TokenName::LEFT_BRACE:
        case TokenName::BANG:
        case TokenName::MINUS:
        case TokenName::TRUE:
        case TokenName::FALSE:
        case TokenName::NULL_VALUE:
        case TokenName::NUMBER:
        case TokenName::STRING:
        case TokenName::IDENTIFIER:
        case TokenName::LEFT_PAREN:
        case TokenName::SUPER:
        case TokenName::THIS:
            stmt = statement();
            statements.push_back(stmt);
            declaration(statements);
            break;
    }
}

Statement* Parser::classDeclaration() {
    std::list<StmtFunction*> methods;
    std::list<StmtVariable*> variables;

    match(TokenName::CLASS);
    match(TokenName::IDENTIFIER);
    IdToken* name = dynamic_cast<IdToken *>(previous);
    ExprVariable* superClass = classInheritance();
    match(TokenName::LEFT_BRACE);
    classElement(methods, variables);
    match(TokenName::RIGHT_BRACE);

    return new StmtClass(name, superClass, methods, variables);
}

ExprVariable* Parser::classInheritance() {
    if(preanalysis->getName() == TokenName::EXTENDS){
        match(TokenName::EXTENDS);
        match(TokenName::IDENTIFIER);
        IdToken* nameSuperClass = dynamic_cast<IdToken *>(previous);
        return new ExprVariable(nameSuperClass);
    }
    return nullptr;
}

void Parser::classElement(std::list<StmtFunction*> methods, std::list<StmtVariable*> variables) {
    if(preanalysis->getName() == TokenName::VAR){
        StmtVariable* var = variableDeclaration();
        variables.push_back(var);
        classElement(methods, variables);
    }
    else if(preanalysis->getName() == TokenName::FUN){
        StmtFunction* method = functionDeclaration();
        methods.push_back(method);
        classElement(methods, variables);
    }
}

StmtFunction* Parser::functionDeclaration() {
    match(TokenName::FUN);
    match(TokenName::IDENTIFIER);
    IdToken* name = dynamic_cast<IdToken *>(previous);

    match(TokenName::LEFT_PAREN);
    std::list<IdToken*> params = parametersOptional();
    match(TokenName::RIGHT_PAREN);
    StmtBlock* stmtBlock = block();

    return new StmtFunction(name, params, stmtBlock);
}

StmtVariable* Parser::variableDeclaration() {
    match(TokenName::VAR);
    match(TokenName::IDENTIFIER);
    IdToken* name = dynamic_cast<IdToken *>(previous);

    Expression* initialization = variableInitialization();
    match(TokenName::SEMICOLON);

    return new StmtVariable(name, initialization);
}

Expression* Parser::variableInitialization() {
    if(preanalysis->getName()==TokenName::EQUAL){
        match(TokenName::EQUAL);
        Expression* expr = expression();
        return expr;
    }

    return nullptr;
}

// Statements:

Statement* Parser::statement() {
    switch (preanalysis->getName()) {
        case TokenName::BANG:
        case TokenName::MINUS:
        case TokenName::TRUE:
        case TokenName::FALSE:
        case TokenName::NULL_VALUE:
        case TokenName::NUMBER:
        case TokenName::STRING:
        case TokenName::IDENTIFIER:
        case TokenName::LEFT_PAREN:
        case TokenName::SUPER:
        case TokenName::THIS:
            return expressionStatement();
            break;
        case TokenName::FOR:
            forStatement();
            break;
        case TokenName::IF:
            ifStatement();
            break;
        case TokenName::WHILE:
            whileStatement();
            break;
        case TokenName::PRINT:
            printStatement();
            break;
        case TokenName::RETURN:
            returnStatement();
            break;
        case TokenName::LEFT_BRACE:
            block();
            break;
        default:
            std::stringstream ss;
            ss<<"Error: No se esperaba el token '"<< tokennameToString(preanalysis->getName());
            ss<<"'. Linea: " << preanalysis->getLine();
            throw ParserException(ss.str());
    }
}

StmtExpression* Parser::expressionStatement() {
    Expression* expr = expression();
    match(TokenName::SEMICOLON);
    return new StmtExpression(expr);
}

void Parser::forStatement() {
    match(TokenName::FOR);
    match(TokenName::LEFT_PAREN);
    forStatement1();
    forStatement2();
    forStatement3();
    match(TokenName::RIGHT_PAREN);
    statement();
}

void Parser::forStatement1() {
    switch (preanalysis->getName()) {
        case TokenName::VAR:
            variableDeclaration();
            break;
        case TokenName::BANG:
        case TokenName::MINUS:
        case TokenName::TRUE:
        case TokenName::FALSE:
        case TokenName::NULL_VALUE:
        case TokenName::NUMBER:
        case TokenName::STRING:
        case TokenName::IDENTIFIER:
        case TokenName::LEFT_PAREN:
        case TokenName::SUPER:
        case TokenName::THIS:
            expressionStatement();
            break;
        case TokenName::SEMICOLON:
            match(TokenName::SEMICOLON);
            break;
        default:
            std::stringstream ss;
            ss<<"Error: Expresion no valida, no se esperaba el token '"<< tokennameToString(preanalysis->getName());
            ss<<"'. Linea: " << preanalysis->getLine();
            throw ParserException(ss.str());
    }
}

void Parser::forStatement2() {
    switch (preanalysis->getName()) {
        case TokenName::BANG:
        case TokenName::MINUS:
        case TokenName::TRUE:
        case TokenName::FALSE:
        case TokenName::NULL_VALUE:
        case TokenName::NUMBER:
        case TokenName::STRING:
        case TokenName::IDENTIFIER:
        case TokenName::LEFT_PAREN:
        case TokenName::SUPER:
        case TokenName::THIS:
            expression();
            match(TokenName::SEMICOLON);
            break;
        case TokenName::SEMICOLON:
            match(TokenName::SEMICOLON);
            break;
        default:
            std::stringstream ss;
            ss<<"Error: Expresion no valida, no se esperaba el token '"<< tokennameToString(preanalysis->getName());
            ss<<"'. Linea: " << preanalysis->getLine();
            throw ParserException(ss.str());
    }
}

void Parser::forStatement3() {
    switch (preanalysis->getName()) {
        case TokenName::BANG:
        case TokenName::MINUS:
        case TokenName::TRUE:
        case TokenName::FALSE:
        case TokenName::NULL_VALUE:
        case TokenName::NUMBER:
        case TokenName::STRING:
        case TokenName::IDENTIFIER:
        case TokenName::LEFT_PAREN:
        case TokenName::SUPER:
        case TokenName::THIS:
            expression();
            break;
    }
}

void Parser::ifStatement() {
    match(TokenName::IF);
    match(TokenName::LEFT_PAREN);
    expression();
    match(TokenName::RIGHT_PAREN);
    statement();
    elseStatement();
}

void Parser::elseStatement() {
    if (preanalysis->getName() == TokenName::ELSE) {
        match(TokenName::ELSE);
        statement();
    }
}

void Parser::printStatement() {
    match(TokenName::PRINT);
    expression();
    match(TokenName::SEMICOLON);
}

void Parser::returnStatement() {
    match(TokenName::RETURN);
    returnExpressionOptional();
    match(TokenName::SEMICOLON);
}

void Parser::returnExpressionOptional() {
    switch (preanalysis->getName()) {
        case TokenName::BANG:
        case TokenName::MINUS:
        case TokenName::TRUE:
        case TokenName::FALSE:
        case TokenName::NULL_VALUE:
        case TokenName::NUMBER:
        case TokenName::STRING:
        case TokenName::IDENTIFIER:
        case TokenName::LEFT_PAREN:
        case TokenName::SUPER:
        case TokenName::THIS:
            expression();
            break;
    }
}

void Parser::whileStatement() {
    match(TokenName::WHILE);
    match(TokenName::LEFT_PAREN);
    expression();
    match(TokenName::RIGHT_PAREN);
    statement();
}

StmtBlock* Parser::block() {
    match(TokenName::LEFT_BRACE);
    std::list<Statement*> statements;
    declaration(statements);
    match(TokenName::RIGHT_BRACE);
    return new StmtBlock(statements);
}

// Expressions:

Expression* Parser::expression() {
    return assignament();
}

Expression* Parser::assignament() {
    Expression* izq = logicOr();
    return assignamentOptional(izq);
}

Expression* Parser::assignamentOptional(Expression* izq) {
    if(preanalysis->getName() == TokenName::EQUAL){
        match(TokenName::EQUAL);
        Expression* value = expression();

        if(dynamic_cast<ExprVariable*>(izq)){
            IdToken* name = (dynamic_cast<ExprVariable*>(izq))->getName();
            return new ExprAssignment(name, value);
        }
        else if(dynamic_cast<ExprGet*>(izq)){
            ExprGet* get = dynamic_cast<ExprGet*>(izq);
            return new ExprSet(get->getObject(), get->getName(), value);
        }

        std::stringstream ss;
        ss<<"Error: Expresion no valida, no se esperaba el token '"<< tokennameToString(preanalysis->getName());
        ss<<"'. Linea: " << preanalysis->getLine();
        throw ParserException(ss.str());
    }
    return izq;
}

Expression*  Parser::logicOr() {
    Expression* left = logicAnd();
    return logicOr2(left);
}

Expression*  Parser::logicOr2(Expression* left) {
    if (preanalysis->getName() == TokenName::OR) {
        match(TokenName::OR);
        Token* oper = dynamic_cast<Token *>(previous);
        Expression* right = logicOr();
        return new ExprLogical(left, oper, right);
    }
    return left;
}

Expression* Parser::logicAnd() {
    Expression* left = equality();
    return logicAnd2(left);
}

Expression* Parser::logicAnd2(Expression* left) {
    if (preanalysis->getName() == TokenName::AND) {
        match(TokenName::AND);
        Token* oper = dynamic_cast<Token *>(previous);
        Expression* right = logicAnd();
        return new ExprLogical(left, oper, right);
    }
    return left;
}

Expression* Parser::equality() {
    Expression* left = comparison();
    return equality2(left);
}

Expression* Parser::equality2(Expression* left) {
    if(preanalysis->getName() == TokenName::BANG_EQUAL || preanalysis->getName() == TokenName::EQUAL_EQUAL){
        match(preanalysis->getName());
        Token *oper = dynamic_cast<Token *>(previous);
        Expression* right = equality();
        return new ExprRelational(left, oper, right);
    }
    return left;
}

Expression* Parser::comparison() {
    Expression* left = term();
    return comparison2(left);
}

Expression* Parser::comparison2(Expression* left) {
    if(preanalysis->getName() == TokenName::GREATER || preanalysis->getName() == TokenName::GREATER_EQUAL ||
            preanalysis->getName() == TokenName::LESS || preanalysis->getName() == TokenName::LESS_EQUAL){
        match(preanalysis->getName());
        Token* oper = dynamic_cast<Token *>(previous);
        Expression* right = comparison();
        return new ExprRelational(left, oper, right);
    }
    return left;
}

Expression* Parser::term() {
    Expression* left = factor();
    return term2(left);
}

Expression* Parser::term2(Expression* left) {
    if(preanalysis->getName() == TokenName::MINUS || preanalysis->getName() == TokenName::PLUS){
        match(preanalysis->getName());
        Token* oper = dynamic_cast<Token *>(previous);
        Expression* right = term();
        return new ExprArithmetic(left, oper, right);
    }
    return left;
}

Expression* Parser::factor() {
    Expression* expr = unary();
    return factor2(expr);
}

Expression* Parser::factor2(Expression* left) {
    if(preanalysis->getName() == TokenName::SLASH || preanalysis->getName() == TokenName::STAR ){
        match(preanalysis->getName());
        Token* oper = dynamic_cast<Token *>(previous);
        Expression* rigth = factor();
        return new ExprArithmetic(left, oper, rigth);
    }
    return left;
}

Expression* Parser::unary() {
    if(preanalysis->getName() == TokenName::BANG || preanalysis->getName() == TokenName::MINUS){
        match(preanalysis->getName());
        Token *oper = dynamic_cast<Token *>(previous);
        Expression* expr = unary();
        return new ExprUnary(expr, oper);
    }
    else{
        return call();
    }
}

Expression* Parser::call() {
    Expression* expression = primary();
    return call2(expression);
}

Expression* Parser::call2(Expression* expr) {
    if(preanalysis->getName() == TokenName::LEFT_PAREN){
        match(TokenName::LEFT_PAREN);
        std::list<Expression*> args = argumentsOptional();
        Expression* exprCall = new ExprCallFunction(expr, args);
        return call2(exprCall);
    }
    else if(preanalysis->getName() == TokenName::DOT){
        match(TokenName::DOT);
        match(TokenName::IDENTIFIER);
        Token *name = dynamic_cast<Token *>(previous);
        Expression* exprGet = new ExprGet(expr, name);
        return call2(exprGet);
    }
    return expr;
}

Expression* Parser::primary() {
    if(preanalysis->getName() == TokenName::TRUE){
        match(TokenName::TRUE);
        return new ExprLiteral(true);
    }
    else if(preanalysis->getName() == TokenName::FALSE){
        match(TokenName::FALSE);
        return new ExprLiteral(false);
    }
    else if(preanalysis->getName() == TokenName::NULL_VALUE){
        match(TokenName::NULL_VALUE);
        return new ExprLiteral();
    }
    else if(preanalysis->getName() == TokenName::THIS){
        match(TokenName::THIS);
        return new ExprThis();
    }
    else if(preanalysis->getName() == TokenName::NUMBER){
        NumberToken* t = dynamic_cast<NumberToken *>(preanalysis);
        match(TokenName::NUMBER);

        std::variant value = t->getValue();
        if (std::holds_alternative<int>(value)) {
            return new ExprLiteral(std::get<int>(value));
        }
        else{
            return new ExprLiteral(std::get<double>(value));
        }
    }
    else if(preanalysis->getName() == TokenName::STRING){
        StringToken* t = dynamic_cast<StringToken *>(preanalysis);
        match(TokenName::STRING);
        return new ExprLiteral(t->getValue());
    }
    else if(preanalysis->getName() == TokenName::IDENTIFIER){
        IdToken* t = dynamic_cast<IdToken *>(preanalysis);
        match(TokenName::IDENTIFIER);
        return new ExprVariable(t);
    }
    else if(preanalysis->getName() == TokenName::LEFT_PAREN){
        match(TokenName::LEFT_PAREN);
        Expression* expression1 = expression();
        match(TokenName::RIGHT_PAREN);
        return new ExprGrouping(expression1);
    }
    else if(preanalysis->getName() == TokenName::SUPER) {
        match(TokenName::SUPER);
        match(TokenName::DOT);
        match(TokenName::IDENTIFIER);
        IdToken* t = dynamic_cast<IdToken *>(previous);
        return new ExprSuper(t);
    }
    else{
        std::stringstream ss;
        ss<<"Error: Expresion no valida, no se esperaba el token '"<< tokennameToString(preanalysis->getName());
        ss<<"'. Linea: " << preanalysis->getLine();
        throw ParserException(ss.str());
    }
}

// Auxiliary:

std::list<IdToken*> Parser::parametersOptional() {
    std::list<IdToken*> params;
    if(preanalysis->getName() == TokenName::IDENTIFIER){
        parameters(params);
    }
    return params;
}

void Parser::parameters(std::list<IdToken*> params) {
    match(TokenName::IDENTIFIER);
    IdToken* name = dynamic_cast<IdToken *>(previous);
    params.push_back(name);
    parameters2(params);
}

void Parser::parameters2(std::list<IdToken*> params) {
    if(preanalysis->getName() == TokenName::COMMA){
        match(TokenName::COMMA);
        parameters(params);
    }
}

std::list<Expression*> Parser::argumentsOptional() {
    switch (preanalysis->getName()) {
        case TokenName::BANG:
        case TokenName::MINUS:
        case TokenName::TRUE:
        case TokenName::FALSE:
        case TokenName::NULL_VALUE:
        case TokenName::NUMBER:
        case TokenName::STRING:
        case TokenName::IDENTIFIER:
        case TokenName::LEFT_PAREN:
        case TokenName::SUPER:
        case TokenName::THIS:
            expression();
            arguments();
            std::list<Expression*> arguments;
            return arguments;
            break;
    }
}

void Parser::arguments() {
    if(preanalysis->getName() == TokenName::COMMA){
        match(TokenName::COMMA);
        //expression();
        //arguments();
        argumentsOptional();
    }
}
