#include <sstream>
#include "ExprCallFunction.h"
#include "../../Exceptions/RuntimeException.h"

ExprCallFunction::ExprCallFunction(Expression *callee, Token* paren, std::vector<Expression*> arguments) : callee(callee),
                                                                                            paren(paren),
                                                                                           arguments(arguments) {}

void ExprCallFunction::accept(Visitor *visitor) const {

}