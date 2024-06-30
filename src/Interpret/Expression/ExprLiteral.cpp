#include "ExprLiteral.h"

ExprLiteral::ExprLiteral(std::variant<std::monostate, int, double, bool, std::string> value){
    this->value = value;
}
ExprLiteral::ExprLiteral(){}

void ExprLiteral::accept(Visitor *visitor) {
    visitor->visitLiteralExpr(this);
}
