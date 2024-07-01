#ifndef K_LANG_EXPRVARIABLE_H
#define K_LANG_EXPRVARIABLE_H


#include "Expression.h"

class ExprVariable: public Expression{
private:
    IdToken* name;
public:
    explicit ExprVariable(IdToken *name);
    IdToken* getName();

    void accept(Visitor *visitor) override;
};


#endif //K_LANG_EXPRVARIABLE_H
