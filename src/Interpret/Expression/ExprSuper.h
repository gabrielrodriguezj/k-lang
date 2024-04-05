#ifndef K_LANG_EXPRSUPER_H
#define K_LANG_EXPRSUPER_H


#include "Expression.h"
#include "../../Token/TToken.h"

class ExprSuper: public Expression{
private:
    Token* keyword;
    TToken* method;
public:
    explicit ExprSuper(Token *keyword, TToken *method);

    TData solve(Environment*) override;
};


#endif //K_LANG_EXPRSUPER_H
