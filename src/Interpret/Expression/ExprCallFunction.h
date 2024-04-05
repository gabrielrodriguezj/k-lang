#ifndef K_LANG_EXPRCALLFUNCTION_H
#define K_LANG_EXPRCALLFUNCTION_H

#include <vector>
#include "Expression.h"

class ExprCallFunction: public Expression{
private:
    Expression* callee;
    Token* paren;
    std::vector<Expression*> arguments;
public:
    ExprCallFunction(Expression *callee, Token* paren, std::vector<Expression*> arguments);

    TData solve(Environment*) override;
};


#endif //K_LANG_EXPRCALLFUNCTION_H
