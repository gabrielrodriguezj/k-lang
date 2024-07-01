#ifndef K_LANG_EXPRSUPER_H
#define K_LANG_EXPRSUPER_H


#include "Expression.h"

class ExprSuper: public Expression{
private:
    Token* keyword;
    TToken* method;
public:
    explicit ExprSuper(Token *keyword, TToken *method);

    void accept(Visitor *visitor) override;
};


#endif //K_LANG_EXPRSUPER_H
