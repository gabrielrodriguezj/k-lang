#ifndef K_LANG_EXPRUNARY_H
#define K_LANG_EXPRUNARY_H


#include "Expression.h"

class ExprUnary: public Expression{
private:
    Expression* left;
    Token* oper;
public:
    ExprUnary(Expression *left, Token *oper);

    KData accept(Visitor *visitor) override;

    Expression *getLeft() const;

    Token *getOper() const;
};


#endif //K_LANG_EXPRUNARY_H
