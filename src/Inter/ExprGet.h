#ifndef K_LANG_EXPRGET_H
#define K_LANG_EXPRGET_H


#include "Expression.h"
#include "../Token/Token.h"

class ExprGet: public Expression{
private:
    Expression* object;
    Token* name;
public:
    ExprGet(Expression *object, Token *name);
    TType solve() override;
};


#endif //K_LANG_EXPRGET_H
