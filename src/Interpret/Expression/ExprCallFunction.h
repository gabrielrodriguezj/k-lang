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

    void accept(Visitor *visitor) override;
};


#endif //K_LANG_EXPRCALLFUNCTION_H
