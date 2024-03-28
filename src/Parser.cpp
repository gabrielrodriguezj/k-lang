#include <sstream>
#include "Parser.h"
#include "Scanner.h"
#include "Token/TokenUtil.h"

Parser::Parser(const std::string source) {
    preanalysis = nullptr;
    scanner = new Scanner(source);
}

bool Parser::parse() {
    preanalysis = scanner->next();
    while (true){
        try {
            program();
        }
        catch (ParserException* e){
            std::cout<< e->what();
            return false;
        }


        if(preanalysis->getName() != TokenName::END) {
            std::stringstream ss;
            ss << "Error en el programa";
            std::cout<<ss.str();
            return false;
        } else{
            break;
        }
    }

    return true;
}

void Parser::match(TokenName name) noexcept(false) {
    if(preanalysis->getName() == name){
        preanalysis = scanner->next();
    }
    else{
        std::stringstream ss;
        ss<<"Error: Se esperaba el token '"<< tokennameToString(name);
        ss<<"' pero se recibio el token '" << tokennameToString(preanalysis->getName());
        ss<<"'. Linea: " << preanalysis->getLine();
        // std::cout<<ss.str()<<std::endl;
        throw new ParserException(ss.str());
    }
}

// Declarations:

void Parser::program() noexcept(false) {
    declaration();
}

void Parser::declaration() noexcept(false) {
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

void Parser::classDeclaration() noexcept(false) {
    match(TokenName::CLASS);
    match(TokenName::IDENTIFIER);
    classInheritance();
    match(TokenName::LEFT_BRACE);
    classElement();
    match(TokenName::RIGHT_BRACE);
}

void Parser::classInheritance() noexcept(false) {
    if(preanalysis->getName() == TokenName::EXTENDS){
        match(TokenName::EXTENDS);
        match(TokenName::IDENTIFIER);
    }
}

void Parser::classElement() noexcept(false) {
    if(preanalysis->getName() == TokenName::VAR){
        variableDeclaration();
        classElement();
    }
    else if(preanalysis->getName() == TokenName::FUN){
        functionDeclaration();
        classElement();
    }
}

void Parser::functionDeclaration() noexcept(false) {
    match(TokenName::FUN);
    match(TokenName::IDENTIFIER);
    match(TokenName::LEFT_PAREN);
    parametersOptional();
    match(TokenName::RIGHT_PAREN);
    block();
}

void Parser::variableDeclaration() noexcept(false) {
    match(TokenName::VAR);
    match(TokenName::IDENTIFIER);
    variableInitialization();
    match(TokenName::SEMICOLON);
}

void Parser::variableInitialization() noexcept(false) {
    if(preanalysis->getName()==TokenName::EQUAL){
        match(TokenName::EQUAL);
        expression();
    }
}

// Statements:

void Parser::statement() noexcept(false) {
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
            // std::cout<<ss.str()<<std::endl;
            throw new ParserException(ss.str());
    }
}

void Parser::expressionStatement() noexcept(false) {
    expression();
    match(TokenName::SEMICOLON);
}

void Parser::forStatement() noexcept(false) {
    match(TokenName::FOR);
    match(TokenName::LEFT_PAREN);
    forStatement1();
    forStatement2();
    forStatement3();
    match(TokenName::RIGHT_PAREN);
    statement();
}

void Parser::forStatement1() noexcept(false) {
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
            // std::cout<<ss.str()<<std::endl;
            throw new ParserException(ss.str());
    }
}

void Parser::forStatement2() noexcept(false) {
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
            // std::cout<<ss.str()<<std::endl;
            throw new ParserException(ss.str());
    }
}

void Parser::forStatement3() noexcept(false) {
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

void Parser::ifStatement() noexcept(false) {
    match(TokenName::IF);
    match(TokenName::LEFT_PAREN);
    expression();
    match(TokenName::RIGHT_PAREN);
    statement();
    elseStatement();
}

void Parser::elseStatement() noexcept(false) {
    if (preanalysis->getName() == TokenName::ELSE) {
        match(TokenName::ELSE);
        statement();
    }
}

void Parser::printStatement() noexcept(false) {
    match(TokenName::PRINT);
    expression();
    match(TokenName::SEMICOLON);
}

void Parser::returnStatement() noexcept(false) {
    match(TokenName::RETURN);
    returnExpressionOptional();
    match(TokenName::SEMICOLON);
}

void Parser::returnExpressionOptional() noexcept(false) {
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

void Parser::whileStatement() noexcept(false) {
    match(TokenName::WHILE);
    match(TokenName::LEFT_PAREN);
    expression();
    match(TokenName::RIGHT_PAREN);
    statement();
}

void Parser::block() noexcept(false) {
    match(TokenName::LEFT_BRACE);
    declaration();
    match(TokenName::RIGHT_BRACE);
}

// Expressions:

void Parser::expression() noexcept(false) {
    assignament();
}

void Parser::assignament() noexcept(false) {
    logicOr();
    assignamentOptional();
}

void Parser::assignamentOptional() noexcept(false) {
    if(preanalysis->getName() == TokenName::EQUAL){
        match(TokenName::EQUAL);
        expression();
    }
}

void Parser::logicOr() noexcept(false) {
    logicAnd();
    logicOr2();
}

void Parser::logicOr2() noexcept(false) {
    if (preanalysis->getName() == TokenName::OR) {
        match(TokenName::OR);
        logicOr();
    }
}

void Parser::logicAnd() noexcept(false) {
    equality();
    logicAnd2();
}

void Parser::logicAnd2() noexcept(false) {
    if (preanalysis->getName() == TokenName::AND) {
        match(TokenName::AND);
        logicAnd();
    }
}

void Parser::equality() noexcept(false) {
    comparison();
    equality2();
}

void Parser::equality2() noexcept(false) {
    if(preanalysis->getName() == TokenName::BANG_EQUAL){
        match(TokenName::BANG_EQUAL);
        equality();
    }
    else if(preanalysis->getName() == TokenName::EQUAL_EQUAL){
        match(TokenName::EQUAL_EQUAL);
        equality();
    }
}

void Parser::comparison() noexcept(false) {
    term();
    comparison2();
}

void Parser::comparison2() noexcept(false) {
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

void Parser::term() noexcept(false) {
    factor();
    term2();
}

void Parser::term2() noexcept(false) {
    if(preanalysis->getName() == TokenName::MINUS){
        match(TokenName::MINUS);
        term();
    }
    else if(preanalysis->getName() == TokenName::PLUS){
        match(TokenName::PLUS);
        term();
    }
}

void Parser::factor() noexcept(false) {
    unary();
    factor2();
}

void Parser::factor2() noexcept(false) {
    if(preanalysis->getName() == TokenName::SLASH){
        match(TokenName::SLASH);
        factor();
    }
    else if(preanalysis->getName() == TokenName::STAR){
        match(TokenName::STAR);
        factor();
    }
}

void Parser::unary() noexcept(false) {
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

void Parser::call() noexcept(false) {
    primary();
    call2();
}

void Parser::call2() noexcept(false) {
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

void Parser::primary() noexcept(false) {
    if(preanalysis->getName() == TokenName::TRUE){
        match(TokenName::TRUE);
    }
    else if(preanalysis->getName() == TokenName::FALSE){
        match(TokenName::FALSE);
    }
    else if(preanalysis->getName() == TokenName::NULL_VALUE){
        match(TokenName::NULL_VALUE);
    }
    else if(preanalysis->getName() == TokenName::THIS){
        match(TokenName::THIS);
    }
    else if(preanalysis->getName() == TokenName::NUMBER){
        match(TokenName::NUMBER);
    }
    else if(preanalysis->getName() == TokenName::STRING){
        match(TokenName::STRING);
    }
    else if(preanalysis->getName() == TokenName::IDENTIFIER){
        match(TokenName::IDENTIFIER);
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
        // std::cout<<ss.str()<<std::endl;
        throw new ParserException(ss.str());
    }
}

// Auxiliary:

void Parser::parametersOptional() noexcept(false) {
    if(preanalysis->getName() == TokenName::IDENTIFIER){
        parameters();
    }
}

void Parser::parameters() noexcept(false) {
    match(TokenName::IDENTIFIER);
    parameters2();
}

void Parser::parameters2() noexcept(false) {
    if(preanalysis->getName() == TokenName::COMMA){
        match(TokenName::COMMA);
        //match(TokenName::IDENTIFIER);
        //parameters2();
        parameters();
    }
}

void Parser::argumentsOptional() noexcept(false) {
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

void Parser::arguments() noexcept(false) {
    if(preanalysis->getName() == TokenName::COMMA){
        match(TokenName::COMMA);
        //expression();
        //arguments();
        argumentsOptional();
    }
}
