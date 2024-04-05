#ifndef K_LANG_KCALLABLE_H
#define K_LANG_KCALLABLE_H

#include <list>
#include "Interpreter.h"
#include "TData.h"

class TData;
class Environment;

class KCallable {
public:
    //virtual TData call(std::list<TData> arguments) = 0;

    virtual int arity() = 0;

    virtual TData call(Environment *environment, std::list<TData> arguments) = 0;
};

#endif //K_LANG_KCALLABLE_H
