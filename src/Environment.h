#ifndef K_LANG_ENVIRONMENT_H
#define K_LANG_ENVIRONMENT_H


#include <string>
#include <map>
#include "Token/IdToken.h"
#include "Core/KData.h"

class KData;

class Environment {
private:
    Environment* enclosing{};
    std::map<std::string, KData> values;
public:
    Environment();
    explicit Environment(Environment *enclosing);

    KData get(IdToken*);
    void assign(IdToken*, KData);
    void define(IdToken*, KData);
};


#endif //K_LANG_ENVIRONMENT_H
