#ifndef K_LANG_EXPRSUPER_H
#define K_LANG_EXPRSUPER_H


#include "Expression.h"
#include "../Token/TToken.h"

class ExprSuper: public Expression{
private:
    // Token* keyword;
    TToken* method;
public:
    explicit ExprSuper(TToken *method);

    Object solve() override;
};


#endif //K_LANG_EXPRSUPER_H
