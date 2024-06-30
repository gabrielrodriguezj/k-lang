#include "ExprThis.h"
#include "../../Exceptions/NotImplementedYetException.h"

ExprThis::ExprThis(Token* keyword): keyword(keyword) {}

void ExprThis::accept(Visitor *visitor) const {

}
