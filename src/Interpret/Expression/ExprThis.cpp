#include "ExprThis.h"
#include "../../Exceptions/NotImplementedYetException.h"

ExprThis::ExprThis(Token* keyword): keyword(keyword) {}

TData ExprThis::solve(Environment* environment) {
    throw NotImplementedYetException("Not implemented yet");
}
