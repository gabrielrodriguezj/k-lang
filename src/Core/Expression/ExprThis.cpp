#include "ExprThis.h"
#include "../../Exceptions/NotImplementedYetException.h"

ExprThis::ExprThis(Token* keyword): keyword(keyword) {}

KData ExprThis::accept(Visitor *visitor) {
    return visitor->visitThisExpr(this);
}
