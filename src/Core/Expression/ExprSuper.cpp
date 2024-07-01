#include "ExprSuper.h"
#include "../../Exceptions/NotImplementedYetException.h"

ExprSuper::ExprSuper(Token *keyword, TToken *method) : keyword(keyword), method(method) {}

KData ExprSuper::accept(Visitor *visitor) {
    return visitor->visitSuperExpr(this);
}

