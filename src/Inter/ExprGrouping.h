#ifndef K_LANG_EXPRGROUPING_H
#define K_LANG_EXPRGROUPING_H


#include "Expression.h"

class ExprGrouping: public Expression{
private:
    Expression* expression;
public:
    ExprGrouping(Expression*);
    std::variant<std::monostate, int, double, bool, std::string> solve() override;
};


#endif //K_LANG_EXPRGROUPING_H
