#ifndef K_LANG_EXPRESSION_H
#define K_LANG_EXPRESSION_H


#include "Type/TType.h"

class Expression {
public:
    virtual TType solve() = 0;
};


#endif //K_LANG_EXPRESSION_H
