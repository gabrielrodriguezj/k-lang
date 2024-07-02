#include <sstream>
#include "Environment.h"
#include "Exceptions/RuntimeException.h"

Environment::Environment() {
    enclosing = nullptr;
}

Environment::Environment(Environment *enclosing) : enclosing(enclosing) {}

KData Environment::get(IdToken* name) {
    // check if key is present
    if(values.find(name->getIdentifier()) != values.end()){
        KData data= values[name->getIdentifier()];
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

KData Environment::getAt(int distance, std::string name) {
    return ancestor(distance)->values[name];
}

void Environment::assignAt(int distance, IdToken *name, KData value) {
    ancestor(distance)->values[name->getIdentifier()] = value;
}

Environment* Environment::ancestor(int distance) {
    Environment* environment = this;
    for (int i = 0; i < distance; i++) {
        environment = environment->enclosing;
    }

    return environment;
}

void Environment::assign(IdToken* name, KData value) {
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

void Environment::define(IdToken* name, KData value) {
    // check if key is not present
    if (values.find(name->getIdentifier()) == values.end()) {
        values[name->getIdentifier()] = value;
        return;
    }

    std::stringstream ss;
    ss << "Identificador '" << name->getIdentifier() << "' ya se encuentra definido";
    throw RuntimeException(ss.str());
}
