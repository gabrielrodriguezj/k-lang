#ifndef K_LANG_ENVIRONMENT_H
#define K_LANG_ENVIRONMENT_H


#include <string>
#include <map>
#include "Core/Token/IdToken.h"
#include "Core/KData.h"

class KData;

class Environment {
private:
    Environment* enclosing{};
    std::map<std::string, KData> values;
    Environment* ancestor(int);
public:
    Environment();
    explicit Environment(Environment *enclosing);

    KData get(IdToken*);
    KData getAt(int distance, std::string);
    void assignAt(int, IdToken*, KData);

    void assign(IdToken*, KData);
    void define(IdToken*, KData);
};


#endif //K_LANG_ENVIRONMENT_H
