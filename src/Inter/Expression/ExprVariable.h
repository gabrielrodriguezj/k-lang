#ifndef K_LANG_EXPRVARIABLE_H
#define K_LANG_EXPRVARIABLE_H


#include "Expression.h"
#include "../../Token/IdToken.h"

class ExprVariable: public Expression{
private:
    IdToken* name;
public:
    explicit ExprVariable(IdToken *name);

    TData solve() override;
    IdToken* getName();
};


#endif //K_LANG_EXPRVARIABLE_H
