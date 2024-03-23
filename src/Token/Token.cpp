//
// Created by gabri on 17/03/2024.
//

#include <sstream>
#include "Token.h"

Token::Token(TokenName name) : TToken(name) {}

std::string Token::toString() {
    std::stringstream ss;
    ss << "<";

    switch (TToken::getName()) {
        case TokenName::LEFT_PAREN:
            ss << "(";
            break;
        case TokenName::RIGHT_PAREN:
            ss << ")";
            break;
        case TokenName::LEFT_BRACE:
            ss << "{";
            break;
        case TokenName::RIGHT_BRACE:
            ss << "}";
            break;
        case TokenName::COMMA:
            ss << ",";
            break;
        case TokenName::DOT:
            ss << ".";
            break;
        case TokenName::MINUS:
            ss << "-";
            break;
        case TokenName::PLUS:
            ss << "+";
            break;
        case TokenName::SEMICOLON:
            ss << ";";
            break;
        case TokenName::SLASH:
            ss << "/";
            break;
        case TokenName::STAR:
            ss << "*";
            break;
        case TokenName::BANG:
            ss << "!";
            break;
        case TokenName::BANG_EQUAL:
            ss << "!=";
            break;
        case TokenName::EQUAL:
            ss << "=";
            break;
        case TokenName::EQUAL_EQUAL:
            ss << "==";
            break;
        case TokenName::GREATER:
            ss << ">";
            break;
        case TokenName::GREATER_EQUAL:
            ss << ">=";
            break;
        case TokenName::LESS:
            ss << "<";
            break;
        case TokenName::LESS_EQUAL:
            ss << "<=";
            break;
        case TokenName::IDENTIFIER:
            ss << "ID";
            break;
        case TokenName::STRING:
            ss << "STRING";
            break;
        case TokenName::NUMBER:
            ss << "NUMBER";
            break;
        case TokenName::AND:
            ss << "AND";
            break;
        case TokenName::CLASS:
            ss << "CLASS";
            break;
        case TokenName::ELSE:
            ss << "ELSE";
            break;
        case TokenName::FALSE:
            ss << "FALSE";
            break;
        case TokenName::FUN:
            ss << "FUN";
            break;
        case TokenName::FOR:
            ss << "FOR";
            break;
        case TokenName::IF:
            ss << "IF";
            break;
        case TokenName::NULL_VALUE:
            ss << "NULL";
            break;
        case TokenName::OR:
            ss << "OR";
            break;
        case TokenName::PRINT:
            ss << "PRINT";
            break;
        case TokenName::RETURN:
            ss << "RETURN";
            break;
        case TokenName::SUPER:
            ss << "SUPER";
            break;
        case TokenName::THIS:
            ss << "THIS";
            break;
        case TokenName::TRUE:
            ss << "TRUE";
            break;
        case TokenName::VAR:
            ss << "VAR";
            break;
        case TokenName::WHILE:
            ss << "WHILE";
            break;
        case TokenName::EXTENDS:
            ss << "EXTENDS";
            break;
        case TokenName::END:
            ss << "$";
            break;
        default:
            ss << "Error";
            break;
    }

    ss << ">";
    return ss.str();;
}
