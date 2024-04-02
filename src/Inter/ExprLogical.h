#ifndef K_LANG_EXPRLOGICAL_H
#define K_LANG_EXPRLOGICAL_H


#include "Expression.h"
#include "../Token/Token.h"

class ExprLogical: public Expression{
private:
    Expression* left;
    Token* oper;
    Expression* right;
public:
    ExprLogical(Expression *left, Token *oper, Expression *right);

    TType solve() override;
};


#endif //K_LANG_EXPRLOGICAL_H
