#include "ExprGrouping.h"

ExprGrouping::ExprGrouping(Expression* expression) : expression(expression){}

void ExprGrouping::accept(Visitor *visitor) const {

}
