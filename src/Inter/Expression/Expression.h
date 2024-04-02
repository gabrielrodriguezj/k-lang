#ifndef K_LANG_EXPRESSION_H
#define K_LANG_EXPRESSION_H


#include <variant>
#include <string>
#include "../TData.h"

class Expression {
public:
    virtual TData solve() = 0;
};


#endif //K_LANG_EXPRESSION_H
