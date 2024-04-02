#include <sstream>
#include "Parser.h"
#include "Scanner.h"
#include "Token/TokenUtil.h"
#include "Exceptions/ParserException.h"
#include "Inter/ExprLiteral.h"
#include "Inter/Type/TBool.h"
#include "Inter/Type/TNull.h"
#include "Inter/ExprThis.h"
#include "Token/Token.h"
#include "Token/NumberToken.h"
#include "Inter/Type/TInteger.h"
#include "Inter/Type/TDouble.h"
#include "Token/StringToken.h"
#include "Inter/Type/TString.h"
#include "Inter/ExprVariable.h"

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
        expression();
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

void Parser::expression() {
    assignament();
}

void Parser::assignament() {
    logicOr();
    assignamentOptional();
}

void Parser::assignamentOptional() {
    if(preanalysis->getName() == TokenName::EQUAL){
        match(TokenName::EQUAL);
        expression();
    }
}

void Parser::logicOr() {
    logicAnd();
    logicOr2();
}

void Parser::logicOr2() {
    if (preanalysis->getName() == TokenName::OR) {
        match(TokenName::OR);
        logicOr();
    }
}

void Parser::logicAnd() {
    equality();
    logicAnd2();
}

void Parser::logicAnd2() {
    if (preanalysis->getName() == TokenName::AND) {
        match(TokenName::AND);
        logicAnd();
    }
}

void Parser::equality() {
    comparison();
    equality2();
}

void Parser::equality2() {
    if(preanalysis->getName() == TokenName::BANG_EQUAL){
        match(TokenName::BANG_EQUAL);
        equality();
    }
    else if(preanalysis->getName() == TokenName::EQUAL_EQUAL){
        match(TokenName::EQUAL_EQUAL);
        equality();
    }
}

void Parser::comparison() {
    term();
    comparison2();
}

void Parser::comparison2() {
    if(preanalysis->getName() == TokenName::GREATER){
        match(TokenName::GREATER);
        comparison();
    }
    else if(preanalysis->getName() == TokenName::GREATER_EQUAL){
        match(TokenName::GREATER_EQUAL);
        comparison();
    }
    else if(preanalysis->getName() == TokenName::LESS){
        match(TokenName::LESS);
        comparison();
    }
    else if(preanalysis->getName() == TokenName::LESS_EQUAL){
        match(TokenName::LESS_EQUAL);
        comparison();
    }
}

void Parser::term() {
    factor();
    term2();
}

void Parser::term2() {
    if(preanalysis->getName() == TokenName::MINUS){
        match(TokenName::MINUS);
        term();
    }
    else if(preanalysis->getName() == TokenName::PLUS){
        match(TokenName::PLUS);
        term();
    }
}

void Parser::factor() {
    unary();
    factor2();
}

void Parser::factor2() {
    if(preanalysis->getName() == TokenName::SLASH){
        match(TokenName::SLASH);
        factor();
    }
    else if(preanalysis->getName() == TokenName::STAR){
        match(TokenName::STAR);
        factor();
    }
}

void Parser::unary() {
    if(preanalysis->getName() == TokenName::BANG){
        match(TokenName::BANG);
        unary();
    }
    else if(preanalysis->getName() == TokenName::MINUS){
        match(TokenName::MINUS);
        unary();
    } else{
        call();
    }
}

void Parser::call() {
    Expression* expression = primary();
    call2();
}

void Parser::call2() {
    if(preanalysis->getName() == TokenName::LEFT_PAREN){
        match(TokenName::LEFT_PAREN);
        argumentsOptional();
        call2();
    }
    else if(preanalysis->getName() == TokenName::DOT){
        match(TokenName::DOT);
        match(TokenName::IDENTIFIER);
        call2();
    }
}

Expression* Parser::primary() {
    if(preanalysis->getName() == TokenName::TRUE){
        match(TokenName::TRUE);
        TBool tbool = TBool(true);
        return new ExprLiteral(tbool);
    }
    else if(preanalysis->getName() == TokenName::FALSE){
        match(TokenName::FALSE);
        TBool tbool = TBool(true);
        return new ExprLiteral(tbool);
    }
    else if(preanalysis->getName() == TokenName::NULL_VALUE){
        match(TokenName::NULL_VALUE);
        return new ExprLiteral(TNull());
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
            TInteger tinteger = TInteger(std::get<int>(value));
            return new ExprLiteral(tinteger);
        }
        else{
            TDouble tdouble = TDouble(std::get<double>(value));
            return new ExprLiteral(tdouble);
        }
    }
    else if(preanalysis->getName() == TokenName::STRING){
        StringToken* t = dynamic_cast<StringToken *>(preanalysis);
        match(TokenName::STRING);
        TString tstring = TString(t->getValue());
        return new ExprLiteral(tstring);
    }
    else if(preanalysis->getName() == TokenName::IDENTIFIER){
        TToken* t = preanalysis;
        match(TokenName::IDENTIFIER);
        return new ExprVariable(t);
    }
    else if(preanalysis->getName() == TokenName::LEFT_PAREN){
        match(TokenName::LEFT_PAREN);
        expression();
        match(TokenName::RIGHT_PAREN);
    }
    else if(preanalysis->getName() == TokenName::SUPER){
        match(TokenName::SUPER);
        match(TokenName::DOT);
        match(TokenName::IDENTIFIER);
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

void Parser::argumentsOptional() {
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
