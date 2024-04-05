#include "ExprSuper.h"
#include "../../Exceptions/NotImplementedYetException.h"

ExprSuper::ExprSuper(Token *keyword, TToken *method) : keyword(keyword), method(method) {}

TData ExprSuper::solve(Environment* environment) {
    throw NotImplementedYetException("Not implemented yet");
}
