#ifndef K_LANG_EXPRASSIGNMENT_H
#define K_LANG_EXPRASSIGNMENT_H


#include "../Token/Token.h"
#include "Expression.h"

class ExprAssignment: public Expression{
private:
    Token* name;
    Expression* expression;
public:
    ExprAssignment(Token *name, Expression *expression);

    TData solve() override;
};


#endif //K_LANG_EXPRASSIGNMENT_H
