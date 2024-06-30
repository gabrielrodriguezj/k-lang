#include "ExprRelational.h"

ExprRelational::ExprRelational(Expression *left, Token *oper, Expression *right) : left(left), oper(oper), right(right) {}

void ExprRelational::accept(Visitor *visitor) const {

}
