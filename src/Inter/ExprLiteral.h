#ifndef K_LANG_EXPRLITERAL_H
#define K_LANG_EXPRLITERAL_H


#include "Type/TType.h"
#include "Expression.h"

class ExprLiteral : public Expression{
private:
    TType value;
public:
    ExprLiteral(TType);
    TType solve();
};


#endif //K_LANG_EXPRLITERAL_H
