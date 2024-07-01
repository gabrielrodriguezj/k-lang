#ifndef K_LANG_EXPRRELATIONAL_H
#define K_LANG_EXPRRELATIONAL_H


#include "Expression.h"

class ExprRelational: public Expression{
private:
    Expression* left;
    Token* oper;
    Expression* right;
public:
    ExprRelational(Expression *left, Token *oper, Expression *right);

    KData accept(Visitor *visitor) override;

    Expression *getLeft() const;

    Token *getOper() const;

    Expression *getRight() const;
};


#endif //K_LANG_EXPRRELATIONAL_H
