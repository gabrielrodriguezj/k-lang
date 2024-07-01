#ifndef K_LANG_EXPRARITHMETIC_H
#define K_LANG_EXPRARITHMETIC_H


#include "Expression.h"

class ExprArithmetic: public Expression{
private:
    Expression* left;
    Token* oper;
    Expression* right;
public:
    ExprArithmetic(Expression *left, Token *oper, Expression *right);

    KData accept(VisitorExpression *visitor) override;

    Expression *getLeft() const;

    Token *getOper() const;

    Expression *getRight() const;
};


#endif //K_LANG_EXPRARITHMETIC_H
