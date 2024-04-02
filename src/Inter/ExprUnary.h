#ifndef K_LANG_EXPRUNARY_H
#define K_LANG_EXPRUNARY_H


#include "Expression.h"
#include "../Token/Token.h"

class ExprUnary: public Expression{
private:
    Expression* left;
    Token* oper;
public:
    ExprUnary(Expression *left, Token *oper);

    std::variant<std::monostate, int, double, bool, std::string> solve() override;
};


#endif //K_LANG_EXPRUNARY_H
