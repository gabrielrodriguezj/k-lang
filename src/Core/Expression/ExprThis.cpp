#include "ExprThis.h"
#include "../../Exceptions/NotImplementedYetException.h"

ExprThis::ExprThis(Token* keyword): keyword(keyword) {}

KData ExprThis::accept(VisitorExpression *visitor) {
    return visitor->visitThisExpr(this);
}
