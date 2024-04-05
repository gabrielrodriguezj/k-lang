#ifndef K_LANG_KCALLABLE_H
#define K_LANG_KCALLABLE_H

#include <vector>
#include "Interpreter.h"
#include "TData.h"

class TData;
class Environment;

class KCallable {
public:
    //virtual TData call(std::vector<TData> arguments) = 0;

    virtual int arity() = 0;

    virtual TData call(Environment *environment, std::vector<TData> arguments) = 0;
};

#endif //K_LANG_KCALLABLE_H
