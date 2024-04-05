#ifndef K_LANG_EXPRESSION_H
#define K_LANG_EXPRESSION_H


#include <variant>
#include <string>
#include "../TData.h"
#include "../Environment.h"

class TData;
class Environment;

class Expression {
public:
    virtual TData solve(Environment*) = 0;
};


#endif //K_LANG_EXPRESSION_H
