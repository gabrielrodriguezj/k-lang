#ifndef K_LANG_EXPRARITHMETIC_H
#define K_LANG_EXPRARITHMETIC_H


#include "Expression.h"
#include "../Token/Token.h"

class ExprArithmetic: public Expression{
private:
    Expression* left;
    Token* oper;
    Expression* right;
public:
    ExprArithmetic(Expression *left, Token *oper, Expression *right);
    TType solve() override;
};


#endif //K_LANG_EXPRARITHMETIC_H
