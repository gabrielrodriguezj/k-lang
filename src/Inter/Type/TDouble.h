#ifndef K_LANG_TDOUBLE_H
#define K_LANG_TDOUBLE_H


#include "TType.h"

class TDouble: public TType{
private:
    double value;
public:
    TDouble(double);
    double get();
};


#endif //K_LANG_TDOUBLE_H
