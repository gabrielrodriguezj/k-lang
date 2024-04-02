#ifndef K_LANG_TINTEGER_H
#define K_LANG_TINTEGER_H


#include "TType.h"

class TInteger : public TType{
private:
    int value;
public:
    TInteger(int);
    int get();
};


#endif //K_LANG_TINTEGER_H
