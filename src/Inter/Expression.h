#ifndef K_LANG_EXPRESSION_H
#define K_LANG_EXPRESSION_H


#include <variant>
#include <string>
#include "Object.h"

class Expression {
public:
    virtual Object solve() = 0;
};


#endif //K_LANG_EXPRESSION_H
