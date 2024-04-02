#ifndef K_LANG_EXPRASSIGNMENT_H
#define K_LANG_EXPRASSIGNMENT_H


#include "../Token/Token.h"
#include "Expression.h"
#include "../Token/IdToken.h"

class ExprAssignment: public Expression{
private:
    IdToken* name;
    Expression* expression;
public:
    ExprAssignment(IdToken *name, Expression *expression);

    TData solve() override;
};


#endif //K_LANG_EXPRASSIGNMENT_H
