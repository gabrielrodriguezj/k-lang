#ifndef K_LANG_EXPRVARIABLE_H
#define K_LANG_EXPRVARIABLE_H


#include "Expression.h"
#include "../Token/Token.h"

class ExprVariable: public Expression{
private:
    Token* name;
public:
    explicit ExprVariable(Token *name);

    TType solve() override;
};


#endif //K_LANG_EXPRVARIABLE_H
