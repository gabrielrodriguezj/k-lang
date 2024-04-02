#ifndef K_LANG_EXPRVARIABLE_H
#define K_LANG_EXPRVARIABLE_H


#include "Expression.h"
#include "../Token/Token.h"

class ExprVariable: public Expression{
private:
    Token* name;
public:
    explicit ExprVariable(Token *name);

    Object solve() override;
    Token* getName();
};


#endif //K_LANG_EXPRVARIABLE_H
