#include "ExprSuper.h"
#include "../../Exceptions/NotImplementedYetException.h"

ExprSuper::ExprSuper(Token *keyword, TToken *method) : keyword(keyword), method(method) {}

KData ExprSuper::accept(VisitorExpression *visitor) {
    return visitor->visitSuperExpr(this);
}

