#ifndef K_LANG_EXPRGROUPING_H
#define K_LANG_EXPRGROUPING_H


#include "Expression.h"

class ExprGrouping: public Expression{
private:
    Expression* expression;
public:
    ExprGrouping(Expression*);

    KData accept(VisitorExpression *visitor) override;

    Expression *getExpression() const;
};


#endif //K_LANG_EXPRGROUPING_H
