#include "ExprSuper.h"
#include "../../Exceptions/NotImplementedYetException.h"

ExprSuper::ExprSuper(Token *keyword, TToken *method) : keyword(keyword), method(method) {}

void ExprSuper::accept(Visitor *visitor) const {

}

