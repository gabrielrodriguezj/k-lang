#ifndef K_LANG_EXPRASSIGNMENT_H
#define K_LANG_EXPRASSIGNMENT_H

#include "Expression.h"

class ExprAssignment: public Expression{
private:
    IdToken* name;
    Expression* expression;
public:
    ExprAssignment(IdToken *name, Expression *expression);

    void accept(Visitor *visitor) const override;
};


#endif //K_LANG_EXPRASSIGNMENT_H
