#include "ExprSet.h"
#include "../../Exceptions/NotImplementedYetException.h"

ExprSet::ExprSet(Expression *object, Token *name, Expression *value) : object(object), name(name), value(value) {}

KData ExprSet::accept(VisitorExpression *visitor) {
    return visitor->visitSetExpr(this);
}
