#ifndef K_LANG_EXPRSUPER_H
#define K_LANG_EXPRSUPER_H


#include "Expression.h"
#include "../Token/Token.h"

class ExprSuper: public Expression{
private:
    // Token* keyword;
    Token* method;
public:
    explicit ExprSuper(Token *method);

    std::variant<std::monostate, int, double, bool, std::string> solve() override;
};


#endif //K_LANG_EXPRSUPER_H
