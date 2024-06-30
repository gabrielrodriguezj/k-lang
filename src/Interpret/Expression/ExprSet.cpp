#include "ExprSet.h"
#include "../../Exceptions/NotImplementedYetException.h"

ExprSet::ExprSet(Expression *object, Token *name, Expression *value) : object(object), name(name), value(value) {}

void ExprSet::accept(Visitor *visitor) {
    visitor->visitSetExpr(this);
}
