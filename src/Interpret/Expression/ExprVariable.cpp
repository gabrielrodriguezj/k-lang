#include "ExprVariable.h"

ExprVariable::ExprVariable(IdToken *name) : name(name) {}

IdToken* ExprVariable::getName() {
    return name;
}

void ExprVariable::accept(Visitor *visitor) const {

}
