#ifndef K_LANG_KCALLABLE_H
#define K_LANG_KCALLABLE_H

#include <vector>
class KData;
class Environment;

class KCallable {
public:
    //virtual KData call(std::vector<KData> arguments) = 0;

    virtual int arity() = 0;

    virtual KData call(Environment *environment, std::vector<KData> arguments) = 0;
};

#endif //K_LANG_KCALLABLE_H
