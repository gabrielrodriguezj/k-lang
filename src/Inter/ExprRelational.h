#ifndef K_LANG_EXPRRELATIONAL_H
#define K_LANG_EXPRRELATIONAL_H


#include "Expression.h"
#include "../Token/Token.h"

class ExprRelational: public Expression{
private:
    Expression* left;
    Token* oper;
    Expression* right;
public:
    ExprRelational(Expression *left, Token *oper, Expression *right);

    Object solve() override;
};


#endif //K_LANG_EXPRRELATIONAL_H
