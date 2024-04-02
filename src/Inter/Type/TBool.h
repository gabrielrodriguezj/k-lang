#ifndef K_LANG_TBOOL_H
#define K_LANG_TBOOL_H


#include "TType.h"

class TBool: public TType{
private:
    bool value;
public:
    TBool(bool );
    bool get();
};


#endif //K_LANG_TBOOL_H
