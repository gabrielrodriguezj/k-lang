#ifndef K_LANG_ENVIRONMENT_H
#define K_LANG_ENVIRONMENT_H


#include <string>
#include <map>
#include "TData.h"
#include "../Token/IdToken.h"

class Environment {
private:
    Environment* enclosing{};
    std::map<std::string, TData*> values;
public:
    explicit Environment(Environment *enclosing);
    TData* get(IdToken*);
    void assign(IdToken*, TData*);
    void define(IdToken*, TData*);
};


#endif //K_LANG_ENVIRONMENT_H
