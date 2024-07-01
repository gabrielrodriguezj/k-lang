#ifndef K_LANG_EXPRCALLFUNCTION_H
#define K_LANG_EXPRCALLFUNCTION_H

#include "Expression.h"

class ExprCallFunction: public Expression{
private:
    Expression* callee;
    Token* paren;
    std::vector<Expression*> arguments;
public:
    ExprCallFunction(Expression *callee, Token* paren, std::vector<Expression*> arguments);

    KData accept(VisitorExpression *visitor) override;

    Expression *getCallee() const;

    void setCallee(Expression *callee);

    Token *getParen() const;

    void setParen(Token *paren);

    const std::vector<Expression *> &getArguments() const;

    void setArguments(const std::vector<Expression *> &arguments);
};


#endif //K_LANG_EXPRCALLFUNCTION_H
