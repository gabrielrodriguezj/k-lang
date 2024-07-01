#ifndef K_LANG_EXPRTHIS_H
#define K_LANG_EXPRTHIS_H


#include "Expression.h"

class ExprThis: public Expression{
private:
    Token* keyword;
public:
    ExprThis(Token* keyword);

    void accept(Visitor *visitor) override;
};


#endif //K_LANG_EXPRTHIS_H