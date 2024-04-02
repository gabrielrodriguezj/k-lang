#include "Environment.h"

Environment::Environment(Environment *enclosing) : enclosing(enclosing) {}

TData Environment::get(std::string) {
    // not implemented yet
}

void Environment::assign(IdToken name, TData value) {

}

void Environment::define(IdToken name, TData value) {

}
