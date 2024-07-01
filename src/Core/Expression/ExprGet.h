#ifndef K_LANG_EXPRGET_H
#define K_LANG_EXPRGET_H


#include "Expression.h"

class ExprGet: public Expression{
private:
    Expression* object;
    Token* name;
public:
    ExprGet(Expression *object, Token *name);

    Expression* getObject();
    Token* getName();

    KData accept(Visitor *visitor) override;
};


#endif //K_LANG_EXPRGET_H
