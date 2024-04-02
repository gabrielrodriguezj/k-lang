#ifndef K_LANG_EXPRSET_H
#define K_LANG_EXPRSET_H


#include "Expression.h"
#include "../Token/Token.h"

class ExprSet: public Expression {
private:
    Expression* object;
    Token* name;
    Expression* value;
public:
    ExprSet(Expression *object, Token *name, Expression *value);

    Object solve() override;
};


#endif //K_LANG_EXPRSET_H
