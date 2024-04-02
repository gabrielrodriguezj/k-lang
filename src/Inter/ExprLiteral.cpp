#include "ExprLiteral.h"

ExprLiteral::ExprLiteral(TType value): value(value){}

TType ExprLiteral::solve() {
    return value;
}