#include "ExprSuper.h"
#include "../../Exceptions/NotImplementedYetException.h"

ExprSuper::ExprSuper(TToken *method) : method(method) {}

TData ExprSuper::solve(Environment* environment) {
    throw NotImplementedYetException("Not implemented yet");
}
