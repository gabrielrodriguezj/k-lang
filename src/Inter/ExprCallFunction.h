#ifndef K_LANG_EXPRCALLFUNCTION_H
#define K_LANG_EXPRCALLFUNCTION_H

#include <list>
#include "Expression.h"

class ExprCallFunction: public Expression{
private:
    Expression* callee;
    // Token* paren;
    std::list<Expression>* arguments;
public:
    ExprCallFunction(Expression *callee, std::list<Expression> *arguments);

    TType solve() override;
};


#endif //K_LANG_EXPRCALLFUNCTION_H
