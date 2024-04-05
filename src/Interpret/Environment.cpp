#include <sstream>
#include "Environment.h"
#include "../Exceptions/RuntimeException.h"

Environment::Environment(Environment *enclosing) : enclosing(enclosing) {}

TData Environment::get(IdToken* name ) {
    // check if key is present
    if(values.find(name->getIdentifier()) != values.end()){
        TData data= values[name->getIdentifier()];
        return data;
    }

    // uso del enclosing para usar variables declaradas en un "scope" previo
    if(enclosing != nullptr){
        return enclosing->get(name);
    }

    std::stringstream ss;
    ss << "Identificador '" << name->getIdentifier() << "' no definido";
    throw RuntimeException(ss.str());
}

void Environment::assign(IdToken* name, TData value) {
    // check if key is present
    if (values.find(name->getIdentifier()) != values.end()) {
        values[name->getIdentifier()] = value;
        return;
    }

    // uso del enclosing para usar variables declaradas en un "scope" previo
    if (enclosing != nullptr) {
        enclosing->assign(name, value);
        return;
    }

    std::stringstream ss;
    ss << "Identificador '" << name->getIdentifier() << "' no definido";
    throw RuntimeException(ss.str());
}

void Environment::define(IdToken* name, TData value) {
    // check if key is not present
    if (values.find(name->getIdentifier()) == values.end()) {
        values[name->getIdentifier()] = value;
        return;
    }

    std::stringstream ss;
    ss << "Identificador '" << name->getIdentifier() << "' ya se encuentra definido";
    throw RuntimeException(ss.str());
}
