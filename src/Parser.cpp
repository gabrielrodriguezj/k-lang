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
    declaration();
}

void Parser::declaration() {
    switch (preanalysis->getName()) {
        case TokenName::CLASS:
            classDeclaration();
            declaration();
            break;
        case TokenName::FUN:
            functionDeclaration();
            declaration();
            break;
        case TokenName::VAR:
            variableDeclaration();
            declaration();
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
            statement();
            declaration();
            break;
    }
}

void Parser::classDeclaration() {
    match(TokenName::CLASS);
    match(TokenName::IDENTIFIER);
    classInheritance();
    match(TokenName::LEFT_BRACE);
    classElement();
    match(TokenName::RIGHT_BRACE);
}

void Parser::classInheritance() {
    if(preanalysis->getName() == TokenName::EXTENDS){
        match(TokenName::EXTENDS);
        match(TokenName::IDENTIFIER);
    }
}

void Parser::classElement() {
    if(preanalysis->getName() == TokenName::VAR){
        variableDeclaration();
        classElement();
    }
    else if(preanalysis->getName() == TokenName::FUN){
        functionDeclaration();
        classElement();
    }
}

void Parser::functionDeclaration() {
    match(TokenName::FUN);
    match(TokenName::IDENTIFIER);
    match(TokenName::LEFT_PAREN);
    parametersOptional();
    match(TokenName::RIGHT_PAREN);
    block();
}

void Parser::variableDeclaration() {
    match(TokenName::VAR);
    match(TokenName::IDENTIFIER);
    variableInitialization();
    match(TokenName::SEMICOLON);
}

void Parser::variableInitialization() {
    if(preanalysis->getName()==TokenName::EQUAL){
        match(TokenName::EQUAL);
        Expression* expr = expression();
        int a = 0;
    }
}

// Statements:

void Parser::statement() {
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
            expressionStatement();
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

void Parser::expressionStatement() {
    expression();
    match(TokenName::SEMICOLON);
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

void Parser::block() {
    match(TokenName::LEFT_BRACE);
    declaration();
    match(TokenName::RIGHT_BRACE);
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
            Token* name = (dynamic_cast<ExprVariable*>(izq))->getName();
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
        Token* t = dynamic_cast<Token *>(preanalysis);
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

void Parser::parametersOptional() {
    if(preanalysis->getName() == TokenName::IDENTIFIER){
        parameters();
    }
}

void Parser::parameters() {
    match(TokenName::IDENTIFIER);
    parameters2();
}

void Parser::parameters2() {
    if(preanalysis->getName() == TokenName::COMMA){
        match(TokenName::COMMA);
        //match(TokenName::IDENTIFIER);
        //parameters2();
        parameters();
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
