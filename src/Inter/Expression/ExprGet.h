#ifndef K_LANG_EXPRGET_H
#define K_LANG_EXPRGET_H


#include "Expression.h"
#include "../../Token/Token.h"

class ExprGet: public Expression{
private:
    Expression* object;
    Token* name;
public:
    ExprGet(Expression *object, Token *name);
    TData solve() override;

    Expression* getObject();
    Token* getName();
};


#endif //K_LANG_EXPRGET_H
