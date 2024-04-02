#ifndef K_LANG_EXPRVARIABLE_H
#define K_LANG_EXPRVARIABLE_H


#include "Expression.h"
#include "../Token/TToken.h"

class ExprVariable: public Expression{
private:
    TToken* name;
public:
    explicit ExprVariable(TToken *name);

    std::variant<std::monostate, int, double, bool, std::string> solve() override;
};


#endif //K_LANG_EXPRVARIABLE_H
