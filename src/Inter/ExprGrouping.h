#ifndef K_LANG_EXPRGROUPING_H
#define K_LANG_EXPRGROUPING_H


#include "Expression.h"

class ExprGrouping: public Expression{
private:
    Expression* expression;
public:
    ExprGrouping(Expression*);
    TType solve();
};


#endif //K_LANG_EXPRGROUPING_H
