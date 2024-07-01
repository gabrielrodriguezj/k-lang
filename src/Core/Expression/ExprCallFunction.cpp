#include <sstream>
#include "ExprCallFunction.h"
#include "../../Exceptions/RuntimeException.h"

ExprCallFunction::ExprCallFunction(Expression *callee, Token* paren, std::vector<Expression*> arguments) : callee(callee),
                                                                                            paren(paren),
                                                                                           arguments(arguments) {}

void ExprCallFunction::accept(Visitor *visitor) {
    visitor->visitCallExpr(this);
}

Expression *ExprCallFunction::getCallee() const {
    return callee;
}

void ExprCallFunction::setCallee(Expression *callee) {
    ExprCallFunction::callee = callee;
}

Token *ExprCallFunction::getParen() const {
    return paren;
}

void ExprCallFunction::setParen(Token *paren) {
    ExprCallFunction::paren = paren;
}

const std::vector<Expression *> &ExprCallFunction::getArguments() const {
    return arguments;
}

void ExprCallFunction::setArguments(const std::vector<Expression *> &arguments) {
    ExprCallFunction::arguments = arguments;
}
