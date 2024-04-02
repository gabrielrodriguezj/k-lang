#ifndef K_LANG_EXPRLITERAL_H
#define K_LANG_EXPRLITERAL_H


#include "Expression.h"

class ExprLiteral : public Expression{
private:
    std::variant<std::monostate, int, double, bool, std::string> value;
public:
    ExprLiteral(std::variant<std::monostate, int, double, bool, std::string>);
    ExprLiteral();
    std::variant<std::monostate, int, double, bool, std::string> solve() override;
};


#endif //K_LANG_EXPRLITERAL_H