#ifndef K_LANG_EXPRASSIGNMENT_H
#define K_LANG_EXPRASSIGNMENT_H

#include "Expression.h"

class ExprAssignment: public Expression{
private:
    IdToken* name;
    Expression* expression;
public:
    ExprAssignment(IdToken *name, Expression *expression);

    KData accept(VisitorExpression *visitor) override;

    IdToken *getName() const;

    Expression *getExpression() const;
};


#endif //K_LANG_EXPRASSIGNMENT_H
