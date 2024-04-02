#ifndef K_LANG_EXPRUNARY_H
#define K_LANG_EXPRUNARY_H


#include "Expression.h"
#include "../Token/Token.h"

class ExprUnary: public Expression{
private:
    Expression* left;
    Token* oper;
public:
    ExprUnary(Expression *left, Token *oper);

    TType solve() override;
};


#endif //K_LANG_EXPRUNARY_H
