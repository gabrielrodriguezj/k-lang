#ifndef K_LANG_EXPRASSIGNMENT_H
#define K_LANG_EXPRASSIGNMENT_H


#include "Expression.h"
//#include "../../Token/IdToken.h"

//class Visitor;

class ExprAssignment: public Expression{
private:
    IdToken* name;
    Expression* expression;
public:
    ExprAssignment(IdToken *name, Expression *expression);

    TData solve(Environment*) override;
};


#endif //K_LANG_EXPRASSIGNMENT_H
