#ifndef K_LANG_EXPRSET_H
#define K_LANG_EXPRSET_H


#include "Expression.h"

class ExprSet: public Expression {
private:
    Expression* object;
    Token* name;
    Expression* value;
public:
    ExprSet(Expression *object, Token *name, Expression *value);

    void accept(Visitor *visitor) const override;
};


#endif //K_LANG_EXPRSET_H
